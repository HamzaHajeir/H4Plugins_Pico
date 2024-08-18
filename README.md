# PlatformIO Environment Running H4Plugins System

## To run: 
- Change WiFi SSID/PSK in main.cpp.
- Change the MQTT server url to meet the available one in main.cpp. Note TLS conencteions are not supported yet.
- Upload File system `pio run -t uploadfs`
- Upload built binary `pio run -t upload`
- Open device monitor `pio device monitor`

Once connected to the access point the IP is printed out. Browse it.

## PIO Environments
The project specifies two environments, `pico`, and `rp2040`. `pico` is the one defined with WiFi capabilities `board = rpipicow`. 