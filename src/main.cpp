#include <Arduino.h>

#define USE_MQTT 1
#define H4P_VERBOSE 0
#include <H4Plugins.h>

H4_USE_PLUGINS(0, H4_Q_CAPACITY, false) // Serial baud rate, Q size, SerialCmd autostop

H4P_SerialLogger h4sl;
#if H4P_USE_WIFI_AP
H4P_WiFi h4wifi("RPIPicoW");
#if USE_MQTT
H4P_AsyncMQTT h4mqtt;
#endif
#else
H4P_WiFi h4wifi("**WIFI_SSID**", "**WIFI_PSK**", "RPIPicoW");
#if USE_MQTT
H4P_AsyncMQTT h4mqtt("http://192.168.100.4:1883");
#endif
#endif
H4P_Heartbeat h4hb;
H4P_BinarySwitch h4onoff(18, ACTIVE_LOW, H4P_UILED_ORANGE, OFF, 10000);

#if USE_MQTT
H4_TIMER mqttSender;
H4_TIMER bigSender;

#define BIG_SIZE 13000
uint8_t big[BIG_SIZE];

void publishDevice(const std::string &topic, const std::string &payload);
void publishDevice(const std::string &topic, long long payload);

void onMQTTConnect() {
	mqttSender = h4.every(2000, []()
					  {
						  publishDevice("heap", _HAL_freeHeap());
						  publishDevice("uptime",h4p.gvGetstring(upTimeTag()));
						  publishDevice("maxbloc",_HAL_maxHeapBlock());
					  });
	
	bigSender = h4.every(3000,[]{
		Serial.printf("SENDING BIG\n");
		h4mqtt.publish("big", &big[0], BIG_SIZE, 1);
	});
}
void onMQTTDisconnect() {
	Serial.printf("onMQTTDisconnect()\n");
	h4.cancel(mqttSender);
	h4.cancel(bigSender);
}


void publishDevice(const std::string &topic, const std::string &payload)
{
	Serial.printf("Publishing %s to %s\n", CSTR(payload), CSTR(topic));
	h4mqtt.publishDevice(topic, payload, 1);
}

void publishDevice(const std::string &topic, long long payload)
{
	publishDevice(topic, stringFromInt(payload, "%lu"));
}
#endif

void onWiFiConnect() {
	Serial.printf("Connected, IP: %s\n",WiFi.localIP().toString().c_str());
}
void onWiFiDisconnect() {
	Serial.printf("WiFi Disconnected\n");
}
void onViewersConnect() {
	Serial.printf("onViewersConnect\n");
	// h4wifi.uiAddGlobal("heap");
	// h4wifi.uiAddGlobal("pool");
}
void onViewersDisconnect() {
	Serial.printf("onViewersDisconnect\n");
}


void h4pGlobalEventHandler(const std::string& svc,H4PE_TYPE t,const std::string& msg)
{
	switch (t)
	{
		H4P_DEFAULT_SYSTEM_HANDLER;
	case H4PE_SERVICE:
#if USE_MQTT
		H4P_SERVICE_ADAPTER(MQTT);
#endif
		H4P_SERVICE_ADAPTER(WiFi);
		break;
	case H4PE_VIEWERS:
		H4P_SERVICE_ADAPTER(Viewers);
		break;
	default:
		break;
	}

}

void h4setup() {
	Serial.begin(921600);
	Serial.printf("Start ...\n");
	h4.every(1000, []{Serial.printf("T=%lu\n", millis());});
#if USE_MQTT
	for (int i=0;i<BIG_SIZE;i++) {
		big[i]=i;
	}
#endif
}