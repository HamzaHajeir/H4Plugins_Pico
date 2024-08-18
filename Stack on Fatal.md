`debug_build_flags = -O0 -ggdb3 -g3`

**CALL STACK:**
```asm
isr_hardfault@0x100030c4 (Unknown Source:98)
<signal handler called>@0xfffffff9 (Unknown Source:0)
__malloc_update_mallinfo@0x10096e1e (\__malloc_update_mallinfo.dbgasm:32)
_mallinfo_r@0x10096e44 (Unknown Source:3569)
mallinfo@0x100922a8 (Unknown Source:89)
RP2040::getUsedHeap@0x1001dc68 (c:\Users\Hamza\.platformio\packages\framework-arduinopico\cores\rp2040\RP2040Support.h:238)
RP2040::getFreeHeap@0x1001dc4a (c:\Users\Hamza\.platformio\packages\framework-arduinopico\cores\rp2040\RP2040Support.h:234)
_HAL_freeHeap@0x1001dda0 (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4Tools\src\H4Tools.cpp:106)
_HAL_maxHeapBlock@0x1001de9a (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4Tools\src\H4Tools.cpp:112)
getMaxPayloadSize@0x10042546 (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4Tools\src\H4Tools.h:115)
PublishPacket::PublishPacket@0x10044682 (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4AsyncMQTT\src\Packet.cpp:448)
operator()@0x1002f276 (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4AsyncMQTT\src\H4AsyncMQTT.cpp:1038)
std::__invoke_impl<short unsigned int, H4AsyncMQTT::publish(char const*, const uint8_t*, size_t, uint8_t, H4AMC_PublishOptions)::<lambda()>&>(std::__invoke_other, struct {...} &)@0x1003de80 (c:\users\hamza\.platformio\packages\toolchain-rp2040-earlephilhower\arm-none-eabi\include\c++\12.3.0\bits\invoke.h:61)
std::__invoke_r<long unsigned int, H4AsyncMQTT::publish(char const*, const uint8_t*, size_t, uint8_t, H4AMC_PublishOptions)::<lambda()>&>(struct {...} &)@0x1003a35e (c:\users\hamza\.platformio\packages\toolchain-rp2040-earlephilhower\arm-none-eabi\include\c++\12.3.0\bits\invoke.h:114)
std::_Function_handler<long unsigned int(), H4AsyncMQTT::publish(char const*, const uint8_t*, size_t, uint8_t, H4AMC_PublishOptions)::<lambda()> >::_M_invoke(const std::_Any_data &)@0x10035432 (c:\users\hamza\.platformio\packages\toolchain-rp2040-earlephilhower\arm-none-eabi\include\c++\12.3.0\bits\std_function.h:290)
std::function<unsigned long ()>::operator()() const@0x10017ab6 (c:\users\hamza\.platformio\packages\toolchain-rp2040-earlephilhower\arm-none-eabi\include\c++\12.3.0\bits\std_function.h:591)
H4AsyncMQTT::_runGuard<unsigned short>(std::function<unsigned long ()>, unsigned short)@0x10031e7a (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4AsyncMQTT\src\H4AsyncMQTT.h:416)
H4AsyncMQTT::publish@0x1002f2fa (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4AsyncMQTT\src\H4AsyncMQTT.cpp:1038)
H4AsyncMQTT::publish@0x1002f354 (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4AsyncMQTT\src\H4AsyncMQTT.cpp:1044)
H4AsyncMQTT::xPublish@0x10004dcc (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4AsyncMQTT\src\H4AsyncMQTT.h:479)
H4P_AsyncMQTT::publishDevice@0x1000566a (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4Plugins\src\H4P_AsyncMQTT.h:88)
```

**__malloc_update_mallinfo:** 
```
0x10096de0: 03 21           	movs	r1, #3
0x10096de2: 12 4b           	ldr	r3, [pc, #72]	@ (0x10096e2c <__malloc_update_mallinfo+76>)
0x10096de4: f0 b5           	push	{r4, r5, r6, r7, lr}
0x10096de6: 9a 68           	ldr	r2, [r3, #8]
0x10096de8: 52 68           	ldr	r2, [r2, #4]
0x10096dea: 8a 43           	bics	r2, r1
0x10096dec: 14 00           	movs	r4, r2
0x10096dee: 02 39           	subs	r1, #2
0x10096df0: 0f 2a           	cmp	r2, #15
0x10096df2: 00 dc           	bgt.n	0x10096df6 <__malloc_update_mallinfo+22>
0x10096df4: 00 21           	movs	r1, #0
0x10096df6: fe 20           	movs	r0, #254	@ 0xfe
0x10096df8: 03 27           	movs	r7, #3
0x10096dfa: 80 00           	lsls	r0, r0, #2
0x10096dfc: 1e 18           	adds	r6, r3, r0
0x10096dfe: 58 69           	ldr	r0, [r3, #20]
0x10096e00: 08 33           	adds	r3, #8
0x10096e02: 98 42           	cmp	r0, r3
0x10096e04: 0b d1           	bne.n	0x10096e1e <__malloc_update_mallinfo+62>
0x10096e06: 86 42           	cmp	r6, r0
0x10096e08: 07 d1           	bne.n	0x10096e1a <__malloc_update_mallinfo+58>
0x10096e0a: 09 4b           	ldr	r3, [pc, #36]	@ (0x10096e30 <__malloc_update_mallinfo+80>)
0x10096e0c: 59 60           	str	r1, [r3, #4]
0x10096e0e: 19 68           	ldr	r1, [r3, #0]
0x10096e10: 1a 62           	str	r2, [r3, #32]
0x10096e12: 89 1a           	subs	r1, r1, r2
0x10096e14: d9 61           	str	r1, [r3, #28]
0x10096e16: 5c 62           	str	r4, [r3, #36]	@ 0x24
0x10096e18: f0 bd           	pop	{r4, r5, r6, r7, pc}
0x10096e1a: 03 00           	movs	r3, r0
0x10096e1c: ef e7           	b.n	0x10096dfe <__malloc_update_mallinfo+30>
>> 0x10096e1e: 45 68           	ldr	r5, [r0, #4]
0x10096e20: 01 31           	adds	r1, #1
0x10096e22: bd 43           	bics	r5, r7
0x10096e24: c0 68           	ldr	r0, [r0, #12]
0x10096e26: 52 19           	adds	r2, r2, r5
0x10096e28: eb e7           	b.n	0x10096e02 <__malloc_update_mallinfo+34>
0x10096e2a: c0 46           	nop			@ (mov r8, r8)
0x10096e2c: 24 15           	asrs	r4, r4, #20
0x10096e2e: 00 20           	movs	r0, #0
0x10096e30: 88 20           	movs	r0, #136	@ 0x88
0x10096e32: 00 20           	movs	r0, #0
```

**REGISTERS:**
> r0=0x00000199
> r1=0x00000003
> r3=0x2001f358
> r4=0x00005178
> r5=0x2001a170
> r6=0x2000191c
> r7=0x00000003
> r8=0x2001ae50
> r9=0x00000001
> r10=0xffffffff
> r11=0xffffffff
> r12=0x20000167
> sp=0x20041878
> lr=0xfffffff9
> pc=0x100030c6
> xPSR=0x81000003
> msp=0x20041878
> psp=0xfffffffc
> primask=0x00000000
> basepri=0x00000000
> faultmask=0x00000000
> control=0x00000000


---------

`debug_build_flags = -Og -ggdb3 -g3`

**CALL STACK:**
```
isr_hardfault@0x100030c4 (Unknown Source:98)
<signal handler called>@0xfffffff9 (Unknown Source:0)
__malloc_update_mallinfo@0x1003d69a (\__malloc_update_mallinfo.dbgasm:32)
_mallinfo_r@0x1003d6c0 (\_mallinfo_r.dbgasm:7)
mallinfo@0x10038b24 (\mallinfo.dbgasm:7)
RP2040::getUsedHeap@0x10009c40 (c:\Users\Hamza\.platformio\packages\framework-arduinopico\cores\rp2040\RP2040Support.h:238)
RP2040::getFreeHeap@0x10009c40 (c:\Users\Hamza\.platformio\packages\framework-arduinopico\cores\rp2040\RP2040Support.h:234)
_HAL_freeHeap@0x10009c74 (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4Tools\src\H4Tools.cpp:106)
_HAL_maxHeapBlock@0x10009c94 (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4Tools\src\H4Tools.cpp:112)
operator()@0x10005d08 (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\src\main.cpp:289)
std::__invoke_impl<void, onMQTTConnect()::<lambda()>&>@0x10005d36 (c:\users\hamza\.platformio\packages\toolchain-rp2040-earlephilhower\arm-none-eabi\include\c++\12.3.0\bits\invoke.h:60)
std::__invoke_r<void, onMQTTConnect()::<lambda()>&>@0x10005d36 (c:\users\hamza\.platformio\packages\toolchain-rp2040-earlephilhower\arm-none-eabi\include\c++\12.3.0\bits\invoke.h:111)
std::_Function_handler<void(), onMQTTConnect()::<lambda()> >::_M_invoke(const std::_Any_data &)@0x10005d36 (c:\users\hamza\.platformio\packages\toolchain-rp2040-earlephilhower\arm-none-eabi\include\c++\12.3.0\bits\std_function.h:290)
std::function<void ()>::operator()() const@0x10007974 (c:\users\hamza\.platformio\packages\toolchain-rp2040-earlephilhower\arm-none-eabi\include\c++\12.3.0\bits\std_function.h:591)
task::operator()@0x10008996 (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4\src\H4.cpp:183)
H4::loop@0x10008a4e (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4\src\H4.cpp:426)
loop@0x10008a7c (c:\Users\Hamza\Documents\PlatformIO\Projects\RPi Pico\.pio\libdeps\pico\H4\src\H4.cpp:364)
main@0x100254f6 (c:\Users\Hamza\.platformio\packages\framework-arduinopico\cores\rp2040\main.cpp:150)
```

**__malloc_update_mallinfo:**
```asm
0x1003d65c: 03 21           	movs	r1, #3
0x1003d65e: 12 4b           	ldr	r3, [pc, #72]	@ (0x1003d6a8 <__malloc_update_mallinfo+76>)
0x1003d660: f0 b5           	push	{r4, r5, r6, r7, lr}
0x1003d662: 9a 68           	ldr	r2, [r3, #8]
0x1003d664: 52 68           	ldr	r2, [r2, #4]
0x1003d666: 8a 43           	bics	r2, r1
0x1003d668: 14 00           	movs	r4, r2
0x1003d66a: 02 39           	subs	r1, #2
0x1003d66c: 0f 2a           	cmp	r2, #15
0x1003d66e: 00 dc           	bgt.n	0x1003d672 <__malloc_update_mallinfo+22>
0x1003d670: 00 21           	movs	r1, #0
0x1003d672: fe 20           	movs	r0, #254	@ 0xfe
0x1003d674: 03 27           	movs	r7, #3
0x1003d676: 80 00           	lsls	r0, r0, #2
0x1003d678: 1e 18           	adds	r6, r3, r0
0x1003d67a: 58 69           	ldr	r0, [r3, #20]
0x1003d67c: 08 33           	adds	r3, #8
0x1003d67e: 98 42           	cmp	r0, r3
0x1003d680: 0b d1           	bne.n	0x1003d69a <__malloc_update_mallinfo+62>
0x1003d682: 86 42           	cmp	r6, r0
0x1003d684: 07 d1           	bne.n	0x1003d696 <__malloc_update_mallinfo+58>
0x1003d686: 09 4b           	ldr	r3, [pc, #36]	@ (0x1003d6ac <__malloc_update_mallinfo+80>)
0x1003d688: 59 60           	str	r1, [r3, #4]
0x1003d68a: 19 68           	ldr	r1, [r3, #0]
0x1003d68c: 1a 62           	str	r2, [r3, #32]
0x1003d68e: 89 1a           	subs	r1, r1, r2
0x1003d690: d9 61           	str	r1, [r3, #28]
0x1003d692: 5c 62           	str	r4, [r3, #36]	@ 0x24
0x1003d694: f0 bd           	pop	{r4, r5, r6, r7, pc}
0x1003d696: 03 00           	movs	r3, r0
0x1003d698: ef e7           	b.n	0x1003d67a <__malloc_update_mallinfo+30>
>> 0x1003d69a: 45 68           	ldr	r5, [r0, #4]
0x1003d69c: 01 31           	adds	r1, #1
0x1003d69e: bd 43           	bics	r5, r7
0x1003d6a0: c0 68           	ldr	r0, [r0, #12]
0x1003d6a2: 52 19           	adds	r2, r2, r5
0x1003d6a4: eb e7           	b.n	0x1003d67e <__malloc_update_mallinfo+34>
0x1003d6a6: c0 46           	nop			@ (mov r8, r8)
0x1003d6a8: f4 14           	asrs	r4, r6, #19
0x1003d6aa: 00 20           	movs	r0, #0
0x1003d6ac: 40 20           	movs	r0, #64	@ 0x40
0x1003d6ae: 00 20           	movs	r0, #0
```

**REGISTERS:**
> r0=0x69747075
> r1=0x00000003
> r2=0x200209d8
> r3=0x200014fc
> r4=0x00006ed8
> r5=0x20019a88
> r6=0x200018ec
> r7=0x00000003
> r8=0xffffffff
> r9=0xffffffff
> r10=0xffffffff
> r11=0xffffffff
> r12=0x2000014f
> sp=0x20041e80
> lr=0xfffffff9
> pc=0x100030c4
> xPSR=0x21000003
> msp=0x20041e80
> psp=0xfffffffc
> primask=0x00000000
> basepri=0x00000000
> faultmask=0x00000000
> control=0x00000000