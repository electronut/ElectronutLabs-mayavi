EESchema Schematic File Version 2
LIBS:mayavi_ver0.1-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:mayavi
LIBS:mayavi_ver0.1-cache
EELAYER 25 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "Mayavi"
Date ""
Rev "Ver 0.1"
Comp "Electronut Labs"
Comment1 "electronut.in"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LIS2DH12 U2
U 1 1 5A2B984B
P 5935 8315
F 0 "U2" H 6410 7830 60  0000 C CNN
F 1 "LIS2DH12" H 6365 9035 60  0000 C CNN
F 2 "boostaBLE:LIS2DH12-LGA12_2X2MM" H 5935 8315 60  0001 C CNN
F 3 "" H 5935 8315 60  0000 C CNN
	1    5935 8315
	1    0    0    -1  
$EndComp
NoConn ~ 19655 4045
$Comp
L GND #PWR01
U 1 1 5A2BA01D
P 5245 8720
F 0 "#PWR01" H 5245 8470 50  0001 C CNN
F 1 "GND" H 5245 8570 50  0000 C CNN
F 2 "" H 5245 8720 50  0001 C CNN
F 3 "" H 5245 8720 50  0001 C CNN
	1    5245 8720
	1    0    0    -1  
$EndComp
$Comp
L C_Small C3
U 1 1 5A2BAA87
P 5060 8220
F 0 "C3" H 4945 8290 50  0000 L CNN
F 1 "0.1uF" H 4835 8150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5060 8220 50  0001 C CNN
F 3 "" H 5060 8220 50  0001 C CNN
	1    5060 8220
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5A2BB208
P 5060 8470
F 0 "#PWR02" H 5060 8220 50  0001 C CNN
F 1 "GND" H 5060 8320 50  0000 C CNN
F 2 "" H 5060 8470 50  0001 C CNN
F 3 "" H 5060 8470 50  0001 C CNN
	1    5060 8470
	1    0    0    -1  
$EndComp
$Comp
L C_Small C2
U 1 1 5A2BB38B
P 4460 8085
F 0 "C2" H 4345 8155 50  0000 L CNN
F 1 "0.1uF" H 4235 8015 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4460 8085 50  0001 C CNN
F 3 "" H 4460 8085 50  0001 C CNN
	1    4460 8085
	1    0    0    -1  
$EndComp
$Comp
L C_Small C1
U 1 1 5A2BB3E0
P 4185 8085
F 0 "C1" H 4070 8155 50  0000 L CNN
F 1 "10uF" H 3960 8015 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4185 8085 50  0001 C CNN
F 3 "" H 4185 8085 50  0001 C CNN
	1    4185 8085
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5A2BB9A6
P 4460 8360
F 0 "#PWR03" H 4460 8110 50  0001 C CNN
F 1 "GND" H 4460 8210 50  0000 C CNN
F 2 "" H 4460 8360 50  0001 C CNN
F 3 "" H 4460 8360 50  0001 C CNN
	1    4460 8360
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5A2BBB3B
P 4185 8360
F 0 "#PWR04" H 4185 8110 50  0001 C CNN
F 1 "GND" H 4185 8210 50  0000 C CNN
F 2 "" H 4185 8360 50  0001 C CNN
F 3 "" H 4185 8360 50  0001 C CNN
	1    4185 8360
	1    0    0    -1  
$EndComp
$Comp
L R_Small R5
U 1 1 5A2BED80
P 6940 5795
F 0 "R5" H 6970 5815 50  0000 L CNN
F 1 "10K" H 6970 5755 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" H 6940 5795 50  0001 C CNN
F 3 "" H 6940 5795 50  0001 C CNN
	1    6940 5795
	-1   0    0    -1  
$EndComp
$Comp
L R_Small R6
U 1 1 5A2BEF53
P 7070 5795
F 0 "R6" H 7100 5815 50  0000 L CNN
F 1 "10K" H 7100 5755 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" H 7070 5795 50  0001 C CNN
F 3 "" H 7070 5795 50  0001 C CNN
	1    7070 5795
	1    0    0    -1  
$EndComp
Text GLabel 7610 8265 2    39   Input ~ 0
SDA
Text GLabel 7610 8565 2    39   Input ~ 0
SCL
Text GLabel 7610 7815 2    39   Input ~ 0
INT1
Text GLabel 7610 7965 2    39   Input ~ 0
INT2
Text GLabel 12675 5240 2    39   Input ~ 0
SWDCLK
Text GLabel 12675 5140 2    39   Input ~ 0
SWDIO
Text GLabel 11925 6040 2    39   Input ~ 0
RESET
$Comp
L SW_PUSH SW3
U 1 1 5A2BB78D
P 5320 6410
F 0 "SW3" H 5370 6510 50  0000 L CNN
F 1 "SW_Push" H 5320 6350 50  0000 C CNN
F 2 "boostaBLE:peter-switch" H 5320 6610 50  0001 C CNN
F 3 "" H 5320 6610 50  0001 C CNN
	1    5320 6410
	0    1    1    0   
$EndComp
$Comp
L GND #PWR05
U 1 1 5A2BC62D
P 5320 6770
F 0 "#PWR05" H 5320 6520 50  0001 C CNN
F 1 "GND" H 5320 6620 50  0000 C CNN
F 2 "" H 5320 6770 50  0001 C CNN
F 3 "" H 5320 6770 50  0001 C CNN
	1    5320 6770
	1    0    0    -1  
$EndComp
$Comp
L R_Small R4
U 1 1 5A2BDA80
P 5320 5795
F 0 "R4" H 5350 5815 50  0000 L CNN
F 1 "10K" H 5350 5755 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" H 5320 5795 50  0001 C CNN
F 3 "" H 5320 5795 50  0001 C CNN
	1    5320 5795
	1    0    0    -1  
$EndComp
Text GLabel 5005 5595 0    39   Input ~ 0
VDD
Text GLabel 5005 6010 0    39   Input ~ 0
RESET
Text GLabel 11005 8025 0    39   Input ~ 0
SWDIO
Text GLabel 11005 8125 0    39   Input ~ 0
SWDCLK
Text GLabel 11005 8225 0    39   Input ~ 0
VDD
Text GLabel 7610 8115 2    39   Input ~ 0
VDD
Text GLabel 11925 7040 2    39   Input ~ 0
SDA
Text GLabel 11925 6940 2    39   Input ~ 0
SCL
Text GLabel 11925 6640 2    39   Input ~ 0
INT2
$Comp
L CONN_01X06 J5
U 1 1 5A2E7F93
P 11425 8075
F 0 "J5" H 11425 8425 50  0000 C CNN
F 1 "CONN_01X06" V 11525 8075 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 11425 8075 50  0001 C CNN
F 3 "" H 11425 8075 50  0001 C CNN
	1    11425 8075
	1    0    0    1   
$EndComp
$Comp
L GND #PWR06
U 1 1 5A2E90D2
P 11115 8465
F 0 "#PWR06" H 11115 8215 50  0001 C CNN
F 1 "GND" H 11115 8315 50  0000 C CNN
F 2 "" H 11115 8465 50  0001 C CNN
F 3 "" H 11115 8465 50  0001 C CNN
	1    11115 8465
	1    0    0    -1  
$EndComp
Text GLabel 3810 7815 0    39   Input ~ 0
VDD
Text GLabel 4890 7965 0    39   Input ~ 0
VDD
Text GLabel 6805 5610 0    39   Input ~ 0
VDD
$Comp
L nrf52832 U3
U 1 1 5A50AB46
P 10925 5135
F 0 "U3" H 9930 4675 60  0000 C CNN
F 1 "nrf52832" H 12055 6680 60  0000 C CNN
F 2 "boostaBLE:nRF52832" H 10535 5070 60  0001 C CNN
F 3 "" H 10535 5070 60  0000 C CNN
	1    10925 5135
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5A53382B
P 8920 3755
F 0 "#PWR07" H 8920 3505 50  0001 C CNN
F 1 "GND" H 8920 3605 50  0000 C CNN
F 2 "" H 8920 3755 50  0001 C CNN
F 3 "" H 8920 3755 50  0001 C CNN
	1    8920 3755
	0    1    1    0   
$EndComp
$Comp
L GND #PWR08
U 1 1 5A537A78
P 9820 3590
F 0 "#PWR08" H 9820 3340 50  0001 C CNN
F 1 "GND" H 9820 3440 50  0000 C CNN
F 2 "" H 9820 3590 50  0001 C CNN
F 3 "" H 9820 3590 50  0001 C CNN
	1    9820 3590
	1    0    0    -1  
$EndComp
Text GLabel 9570 3205 0    39   Input ~ 0
VDD
$Comp
L GND #PWR09
U 1 1 5A53D913
P 10300 6430
F 0 "#PWR09" H 10300 6180 50  0001 C CNN
F 1 "GND" H 10300 6280 50  0000 C CNN
F 2 "" H 10300 6430 50  0001 C CNN
F 3 "" H 10300 6430 50  0001 C CNN
	1    10300 6430
	1    0    0    -1  
$EndComp
Text GLabel 10075 6050 0    39   Input ~ 0
VDD
$Comp
L C_Small C7
U 1 1 5A5412A2
P 9820 3380
F 0 "C7" H 9830 3450 50  0000 L CNN
F 1 "4.7uF" H 9830 3300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9820 3380 50  0001 C CNN
F 3 "" H 9820 3380 50  0001 C CNN
	1    9820 3380
	1    0    0    -1  
$EndComp
$Comp
L C_Small C6
U 1 1 5A54197B
P 9245 3755
F 0 "C6" V 9200 3805 50  0000 L CNN
F 1 "0.1uF" V 9300 3790 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 9245 3755 50  0001 C CNN
F 3 "" H 9245 3755 50  0001 C CNN
	1    9245 3755
	0    1    1    0   
$EndComp
$Comp
L C_Small C8
U 1 1 5A542E5E
P 10300 6230
F 0 "C8" H 10310 6300 50  0000 L CNN
F 1 "0.1uF" H 10310 6150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 10300 6230 50  0001 C CNN
F 3 "" H 10300 6230 50  0001 C CNN
	1    10300 6230
	1    0    0    -1  
$EndComp
$Comp
L C_Small C10
U 1 1 5A5446CB
P 12920 3725
F 0 "C10" V 12865 3770 50  0000 L CNN
F 1 "0.1uF" V 12980 3775 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 12920 3725 50  0001 C CNN
F 3 "" H 12920 3725 50  0001 C CNN
	1    12920 3725
	0    1    1    0   
$EndComp
$Comp
L GND #PWR010
U 1 1 5A547758
P 13175 3725
F 0 "#PWR010" H 13175 3475 50  0001 C CNN
F 1 "GND" H 13175 3575 50  0000 C CNN
F 2 "" H 13175 3725 50  0001 C CNN
F 3 "" H 13175 3725 50  0001 C CNN
	1    13175 3725
	0    -1   -1   0   
$EndComp
Text GLabel 12550 3455 0    39   Input ~ 0
VDD
$Comp
L L_Small L2
U 1 1 5A54EC93
P 10730 3125
F 0 "L2" V 10775 3085 50  0000 L CNN
F 1 "10uH" V 10680 3035 50  0000 L CNN
F 2 "Inductors_NEOSID:Neosid_Inductor_SM0603CG" H 10730 3125 50  0001 C CNN
F 3 "" H 10730 3125 50  0001 C CNN
	1    10730 3125
	-1   0    0    1   
$EndComp
$Comp
L L_Small L1
U 1 1 5A54F86E
P 10730 2800
F 0 "L1" V 10775 2760 50  0000 L CNN
F 1 "15nH" V 10680 2710 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 10730 2800 50  0001 C CNN
F 3 "" H 10730 2800 50  0001 C CNN
	1    10730 2800
	-1   0    0    1   
$EndComp
$Comp
L C_Small C9
U 1 1 5A55188E
P 10995 2550
F 0 "C9" V 10950 2600 50  0000 L CNN
F 1 "1uF" V 11050 2585 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 10995 2550 50  0001 C CNN
F 3 "" H 10995 2550 50  0001 C CNN
	1    10995 2550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR011
U 1 1 5A552EDB
P 11360 2550
F 0 "#PWR011" H 11360 2300 50  0001 C CNN
F 1 "GND" H 11360 2400 50  0000 C CNN
F 2 "" H 11360 2550 50  0001 C CNN
F 3 "" H 11360 2550 50  0001 C CNN
	1    11360 2550
	0    -1   -1   0   
$EndComp
NoConn ~ 11030 3470
$Comp
L Crystal_GND24 Y1
U 1 1 5A554FD0
P 14920 3960
F 0 "Y1" V 14770 4045 50  0000 L CNN
F 1 "32MHz" V 15020 4120 50  0000 L CNN
F 2 "boostaBLE:32MHz_crystal" H 14920 3960 50  0001 C CNN
F 3 "" H 14920 3960 50  0001 C CNN
	1    14920 3960
	0    1    1    0   
$EndComp
$Comp
L C_Small C16
U 1 1 5A566C8B
P 14135 3720
F 0 "C16" H 14005 3655 50  0000 L CNN
F 1 "12pF" H 13935 3820 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 14135 3720 50  0001 C CNN
F 3 "" H 14135 3720 50  0001 C CNN
	1    14135 3720
	-1   0    0    1   
$EndComp
$Comp
L C_Small C15
U 1 1 5A569233
P 14130 4240
F 0 "C15" H 14000 4175 50  0000 L CNN
F 1 "12pF" H 13930 4315 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 14130 4240 50  0001 C CNN
F 3 "" H 14130 4240 50  0001 C CNN
	1    14130 4240
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR012
U 1 1 5A56B85A
P 14350 4430
F 0 "#PWR012" H 14350 4180 50  0001 C CNN
F 1 "GND" H 14350 4280 50  0000 C CNN
F 2 "" H 14350 4430 50  0001 C CNN
F 3 "" H 14350 4430 50  0001 C CNN
	1    14350 4430
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 5A56BF45
P 14370 3460
F 0 "#PWR013" H 14370 3210 50  0001 C CNN
F 1 "GND" H 14370 3310 50  0000 C CNN
F 2 "" H 14370 3460 50  0001 C CNN
F 3 "" H 14370 3460 50  0001 C CNN
	1    14370 3460
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR014
U 1 1 5A56CC34
P 15250 3605
F 0 "#PWR014" H 15250 3355 50  0001 C CNN
F 1 "GND" H 15250 3455 50  0000 C CNN
F 2 "" H 15250 3605 50  0001 C CNN
F 3 "" H 15250 3605 50  0001 C CNN
	1    15250 3605
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C12
U 1 1 5A570726
P 13330 4225
F 0 "C12" V 13365 4265 50  0000 L CNN
F 1 "100pF" V 13265 4260 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 13330 4225 50  0001 C CNN
F 3 "" H 13330 4225 50  0001 C CNN
	1    13330 4225
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C13
U 1 1 5A571197
P 13330 4410
F 0 "C13" V 13365 4450 50  0000 L CNN
F 1 "NC" V 13265 4445 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 13330 4410 50  0001 C CNN
F 3 "" H 13330 4410 50  0001 C CNN
	1    13330 4410
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR015
U 1 1 5A574102
P 13685 4320
F 0 "#PWR015" H 13685 4070 50  0001 C CNN
F 1 "GND" H 13685 4170 50  0000 C CNN
F 2 "" H 13685 4320 50  0001 C CNN
F 3 "" H 13685 4320 50  0001 C CNN
	1    13685 4320
	0    -1   -1   0   
$EndComp
$Comp
L L_Small L3
U 1 1 5A57873F
P 13375 4740
F 0 "L3" V 13420 4700 50  0000 L CNN
F 1 "3.9uH" V 13325 4650 50  0000 L CNN
F 2 "boostaBLE:SMD_0402" H 13375 4740 50  0001 C CNN
F 3 "" H 13375 4740 50  0001 C CNN
	1    13375 4740
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C11
U 1 1 5A579C54
P 13160 4945
F 0 "C11" H 12985 4880 50  0000 L CNN
F 1 "0.8pF" H 12945 5010 50  0000 L CNN
F 2 "boostaBLE:SMD_C0402" H 13160 4945 50  0001 C CNN
F 3 "" H 13160 4945 50  0001 C CNN
	1    13160 4945
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR016
U 1 1 5A57AFD7
P 13160 5155
F 0 "#PWR016" H 13160 4905 50  0001 C CNN
F 1 "GND" H 13160 5005 50  0000 C CNN
F 2 "" H 13160 5155 50  0001 C CNN
F 3 "" H 13160 5155 50  0001 C CNN
	1    13160 5155
	1    0    0    -1  
$EndComp
NoConn ~ 12530 5040
NoConn ~ 12530 4940
NoConn ~ 9820 4535
NoConn ~ 9820 4435
NoConn ~ 9820 4735
NoConn ~ 9820 4835
NoConn ~ 9820 5035
Text GLabel 11005 7825 0    39   Input ~ 0
SDA
Text GLabel 11005 7925 0    39   Input ~ 0
SCL
NoConn ~ 12530 4840
NoConn ~ 11730 3470
NoConn ~ 9820 4235
NoConn ~ 9820 4335
$Comp
L Buzzer BZ1
U 1 1 5B20D5BE
P 7380 5070
F 0 "BZ1" H 7530 5120 50  0000 L CNN
F 1 "Buzzer" H 7530 5020 50  0000 L CNN
F 2 "" V 7355 5170 50  0001 C CNN
F 3 "" V 7355 5170 50  0001 C CNN
	1    7380 5070
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J2
U 1 1 5B20DC5C
P 4915 2990
F 0 "J2" H 4915 3090 50  0000 C CNN
F 1 "Charging Conn" H 4915 2790 50  0000 C CNN
F 2 "" H 4915 2990 50  0001 C CNN
F 3 "" H 4915 2990 50  0001 C CNN
	1    4915 2990
	1    0    0    -1  
$EndComp
Text GLabel 11925 6140 2    39   Input ~ 0
INT1
Text GLabel 6990 4970 0    60   Input ~ 0
BuzP
Text GLabel 6985 5170 0    60   Input ~ 0
BuzN
$Comp
L Conn_01x04 J3
U 1 1 5B20D86C
P 7340 3335
F 0 "J3" H 7340 3535 50  0000 C CNN
F 1 "OLED Connector" H 7340 3035 50  0000 C CNN
F 2 "" H 7340 3335 50  0001 C CNN
F 3 "" H 7340 3335 50  0001 C CNN
	1    7340 3335
	1    0    0    -1  
$EndComp
Text GLabel 4525 2990 0    60   Input ~ 0
VBAT
$Comp
L GND #PWR017
U 1 1 5B2271B2
P 4525 3195
F 0 "#PWR017" H 4525 2945 50  0001 C CNN
F 1 "GND" H 4525 3045 50  0000 C CNN
F 2 "" H 4525 3195 50  0001 C CNN
F 3 "" H 4525 3195 50  0001 C CNN
	1    4525 3195
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J4
U 1 1 5B2278C5
P 7375 6230
F 0 "J4" H 7375 6330 50  0000 C CNN
F 1 "I2C Test" H 7375 6030 50  0000 C CNN
F 2 "" H 7375 6230 50  0001 C CNN
F 3 "" H 7375 6230 50  0001 C CNN
	1    7375 6230
	1    0    0    -1  
$EndComp
Text GLabel 6890 6230 0    39   Input ~ 0
SDA
Text GLabel 6895 6330 0    39   Input ~ 0
SCL
NoConn ~ 9820 5135
NoConn ~ 11230 5940
Text GLabel 6970 3235 0    49   Input ~ 0
VBAT
Text GLabel 6970 3335 0    49   Input ~ 0
SDA
Text GLabel 6970 3440 0    49   Input ~ 0
SCL
$Comp
L GND #PWR018
U 1 1 5B22AFB1
P 6970 3650
F 0 "#PWR018" H 6970 3400 50  0001 C CNN
F 1 "GND" H 6970 3500 50  0000 C CNN
F 2 "" H 6970 3650 50  0001 C CNN
F 3 "" H 6970 3650 50  0001 C CNN
	1    6970 3650
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J1
U 1 1 5B22B738
P 2755 4050
F 0 "J1" H 2755 4150 50  0000 C CNN
F 1 "3.7V LiPo" H 2755 3850 50  0000 C CNN
F 2 "" H 2755 4050 50  0001 C CNN
F 3 "" H 2755 4050 50  0001 C CNN
	1    2755 4050
	1    0    0    -1  
$EndComp
Text GLabel 2425 4050 0    60   Input ~ 0
VBAT
$Comp
L GND #PWR019
U 1 1 5B22C56B
P 2425 4270
F 0 "#PWR019" H 2425 4020 50  0001 C CNN
F 1 "GND" H 2425 4120 50  0000 C CNN
F 2 "" H 2425 4270 50  0001 C CNN
F 3 "" H 2425 4270 50  0001 C CNN
	1    2425 4270
	1    0    0    -1  
$EndComp
NoConn ~ 11130 3470
NoConn ~ 11230 3470
NoConn ~ 11330 3470
NoConn ~ 11430 3470
NoConn ~ 11530 3470
NoConn ~ 11630 3470
NoConn ~ 11530 5940
NoConn ~ 11430 5940
NoConn ~ 11330 5940
Text GLabel 11925 6840 2    39   Input ~ 0
BuzN
Text GLabel 11925 6740 2    39   Input ~ 0
BuzP
$Comp
L TPS79733MDCKREP U1
U 1 1 5B22847E
P 4540 4190
F 0 "U1" H 4550 3870 60  0000 C CNN
F 1 "TPS79733MDCKREP" H 4570 4525 60  0000 C CNN
F 2 "" H 4540 4190 60  0001 C CNN
F 3 "" H 4540 4190 60  0001 C CNN
	1    4540 4190
	1    0    0    -1  
$EndComp
$Comp
L C_Small C5
U 1 1 5B2292FC
P 5650 4270
F 0 "C5" H 5660 4340 50  0000 L CNN
F 1 "0.47uF" H 5660 4190 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 5650 4270 50  0001 C CNN
F 3 "" H 5650 4270 50  0001 C CNN
	1    5650 4270
	1    0    0    -1  
$EndComp
$Comp
L C_Small C4
U 1 1 5B22967E
P 5090 4535
F 0 "C4" H 5100 4605 50  0000 L CNN
F 1 "0.1uF" H 5100 4455 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 5090 4535 50  0001 C CNN
F 3 "" H 5090 4535 50  0001 C CNN
	1    5090 4535
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 5B229709
P 3790 4350
F 0 "#PWR020" H 3790 4100 50  0001 C CNN
F 1 "GND" H 3790 4200 50  0000 C CNN
F 2 "" H 3790 4350 50  0001 C CNN
F 3 "" H 3790 4350 50  0001 C CNN
	1    3790 4350
	1    0    0    -1  
$EndComp
Text GLabel 5165 4330 2    60   Input ~ 0
VBAT
Text GLabel 5780 4060 2    60   Input ~ 0
VDD
$Comp
L GND #PWR021
U 1 1 5B22B578
P 5650 4435
F 0 "#PWR021" H 5650 4185 50  0001 C CNN
F 1 "GND" H 5650 4285 50  0000 C CNN
F 2 "" H 5650 4435 50  0001 C CNN
F 3 "" H 5650 4435 50  0001 C CNN
	1    5650 4435
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR022
U 1 1 5B22C033
P 5090 4715
F 0 "#PWR022" H 5090 4465 50  0001 C CNN
F 1 "GND" H 5090 4565 50  0000 C CNN
F 2 "" H 5090 4715 50  0001 C CNN
F 3 "" H 5090 4715 50  0001 C CNN
	1    5090 4715
	1    0    0    -1  
$EndComp
Text Notes 10800 7600 0    60   ~ 0
SWD Programming
Text Notes 6095 7340 0    60   ~ 0
Accelerometer
Text Notes 3810 2570 0    60   ~ 0
Power Supply
$Comp
L Antenna AE1
U 1 1 5B22EACF
P 14860 4540
F 0 "AE1" H 14925 4250 50  0000 R CNN
F 1 "Chip Ant" H 15265 4530 50  0000 R CNN
F 2 "" H 14860 4540 50  0001 C CNN
F 3 "" H 14860 4540 50  0001 C CNN
	1    14860 4540
	1    0    0    -1  
$EndComp
$Comp
L L_Small L5
U 1 1 5B22ECB2
P 14280 4740
F 0 "L5" V 14325 4700 50  0000 L CNN
F 1 "3.9uH" V 14230 4650 50  0000 L CNN
F 2 "boostaBLE:SMD_0402" H 14280 4740 50  0001 C CNN
F 3 "" H 14280 4740 50  0001 C CNN
	1    14280 4740
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C14
U 1 1 5B22ED8E
P 13820 4740
F 0 "C14" H 13645 4675 50  0000 L CNN
F 1 "2.2pF" H 13605 4805 50  0000 L CNN
F 2 "boostaBLE:SMD_C0402" H 13820 4740 50  0001 C CNN
F 3 "" H 13820 4740 50  0001 C CNN
	1    13820 4740
	0    -1   -1   0   
$EndComp
$Comp
L L_Small L4
U 1 1 5B22EE81
P 14055 4960
F 0 "L4" V 14100 4920 50  0000 L CNN
F 1 "NC" V 14005 4870 50  0000 L CNN
F 2 "boostaBLE:SMD_0402" H 14055 4960 50  0001 C CNN
F 3 "" H 14055 4960 50  0001 C CNN
	1    14055 4960
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR023
U 1 1 5B230B29
P 14055 5135
F 0 "#PWR023" H 14055 4885 50  0001 C CNN
F 1 "GND" H 14055 4985 50  0000 C CNN
F 2 "" H 14055 5135 50  0001 C CNN
F 3 "" H 14055 5135 50  0001 C CNN
	1    14055 5135
	1    0    0    -1  
$EndComp
NoConn ~ 9820 4635
NoConn ~ 9820 5235
NoConn ~ 9820 4935
$Comp
L SW_PUSH SW2
U 1 1 5B23DC27
P 4255 6350
F 0 "SW2" H 4305 6450 50  0000 L CNN
F 1 "SW_Push" H 4255 6290 50  0000 C CNN
F 2 "boostaBLE:peter-switch" H 4255 6550 50  0001 C CNN
F 3 "" H 4255 6550 50  0001 C CNN
	1    4255 6350
	0    1    1    0   
$EndComp
$Comp
L GND #PWR024
U 1 1 5B23DC2D
P 4255 6710
F 0 "#PWR024" H 4255 6460 50  0001 C CNN
F 1 "GND" H 4255 6560 50  0000 C CNN
F 2 "" H 4255 6710 50  0001 C CNN
F 3 "" H 4255 6710 50  0001 C CNN
	1    4255 6710
	1    0    0    -1  
$EndComp
$Comp
L R_Small R3
U 1 1 5B23DC33
P 4255 5735
F 0 "R3" H 4285 5755 50  0000 L CNN
F 1 "10K" H 4285 5695 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" H 4255 5735 50  0001 C CNN
F 3 "" H 4255 5735 50  0001 C CNN
	1    4255 5735
	1    0    0    -1  
$EndComp
Text GLabel 3940 5535 0    39   Input ~ 0
VDD
Text GLabel 3940 5950 0    39   Input ~ 0
RESET
$Comp
L SW_PUSH SW1
U 1 1 5B23DCDB
P 3045 6300
F 0 "SW1" H 3095 6400 50  0000 L CNN
F 1 "SW_Push" H 3045 6240 50  0000 C CNN
F 2 "boostaBLE:peter-switch" H 3045 6500 50  0001 C CNN
F 3 "" H 3045 6500 50  0001 C CNN
	1    3045 6300
	0    1    1    0   
$EndComp
$Comp
L GND #PWR025
U 1 1 5B23DCE1
P 3045 6660
F 0 "#PWR025" H 3045 6410 50  0001 C CNN
F 1 "GND" H 3045 6510 50  0000 C CNN
F 2 "" H 3045 6660 50  0001 C CNN
F 3 "" H 3045 6660 50  0001 C CNN
	1    3045 6660
	1    0    0    -1  
$EndComp
$Comp
L R_Small R1
U 1 1 5B23DCE7
P 3045 5685
F 0 "R1" H 3075 5705 50  0000 L CNN
F 1 "10K" H 3075 5645 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" H 3045 5685 50  0001 C CNN
F 3 "" H 3045 5685 50  0001 C CNN
	1    3045 5685
	1    0    0    -1  
$EndComp
Text GLabel 2730 5485 0    39   Input ~ 0
VDD
Text GLabel 2730 5900 0    39   Input ~ 0
RESET
$Comp
L PWR_FLAG #FLG026
U 1 1 5B23FF84
P 2320 3335
F 0 "#FLG026" H 2320 3410 50  0001 C CNN
F 1 "PWR_FLAG" H 2320 3485 50  0000 C CNN
F 2 "" H 2320 3335 50  0001 C CNN
F 3 "" H 2320 3335 50  0001 C CNN
	1    2320 3335
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR027
U 1 1 5B240BD3
P 2320 3370
F 0 "#PWR027" H 2320 3120 50  0001 C CNN
F 1 "GND" H 2320 3220 50  0000 C CNN
F 2 "" H 2320 3370 50  0001 C CNN
F 3 "" H 2320 3370 50  0001 C CNN
	1    2320 3370
	1    0    0    -1  
$EndComp
Text GLabel 3895 3490 0    60   Input ~ 0
VDD
$Comp
L R_Small R2
U 1 1 5B241161
P 3960 3750
F 0 "R2" H 3815 3760 50  0000 L CNN
F 1 "100k" H 3715 3655 50  0000 L CNN
F 2 "" H 3960 3750 50  0001 C CNN
F 3 "" H 3960 3750 50  0001 C CNN
	1    3960 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5425 8265 5245 8265
Wire Wire Line
	5245 8115 5245 8720
Wire Wire Line
	5425 8415 5245 8415
Connection ~ 5245 8415
Wire Wire Line
	5425 8565 5245 8565
Connection ~ 5245 8565
Wire Wire Line
	5425 8115 5245 8115
Connection ~ 5245 8265
Wire Wire Line
	4890 7965 5425 7965
Wire Wire Line
	3810 7815 5425 7815
Wire Wire Line
	7360 8265 7610 8265
Wire Wire Line
	7360 8565 7610 8565
Wire Wire Line
	7360 7965 7610 7965
Wire Wire Line
	7360 7815 7610 7815
Wire Wire Line
	5060 8120 5060 7965
Connection ~ 5060 7965
Wire Wire Line
	5060 8320 5060 8470
Wire Wire Line
	4185 7985 4185 7815
Connection ~ 4185 7815
Wire Wire Line
	4460 7985 4460 7815
Connection ~ 4460 7815
Wire Wire Line
	4460 8185 4460 8360
Wire Wire Line
	4185 8185 4185 8360
Wire Wire Line
	6805 5610 7070 5610
Wire Wire Line
	7070 5610 7070 5695
Wire Wire Line
	6940 5695 6940 5610
Connection ~ 6940 5610
Wire Wire Line
	5320 5695 5320 5595
Wire Wire Line
	5320 5595 5005 5595
Wire Wire Line
	11225 8225 11005 8225
Wire Wire Line
	11225 8125 11005 8125
Wire Wire Line
	11225 8025 11005 8025
Wire Wire Line
	7360 8115 7610 8115
Wire Wire Line
	7360 8415 7500 8415
Wire Wire Line
	11225 8325 11115 8325
Wire Wire Line
	11115 8325 11115 8465
Wire Wire Line
	11225 7925 11005 7925
Wire Wire Line
	11225 7825 11005 7825
Wire Wire Line
	9820 4135 9560 4135
Wire Wire Line
	9560 4135 9560 3755
Wire Wire Line
	9560 3755 9345 3755
Wire Wire Line
	9145 3755 8920 3755
Wire Wire Line
	10635 3205 10635 3470
Wire Wire Line
	9570 3205 10635 3205
Wire Wire Line
	9820 3205 9820 3280
Wire Wire Line
	9820 3480 9820 3590
Connection ~ 9820 3205
Wire Wire Line
	10635 6050 10635 5935
Wire Wire Line
	10075 6050 10635 6050
Wire Wire Line
	10300 6130 10300 6050
Connection ~ 10300 6050
Wire Wire Line
	10300 6330 10300 6430
Wire Wire Line
	12675 4140 12530 4140
Wire Wire Line
	12675 3455 12675 4140
Wire Wire Line
	12675 3455 12550 3455
Wire Wire Line
	12820 3725 12675 3725
Connection ~ 12675 3725
Wire Wire Line
	13020 3725 13175 3725
Wire Wire Line
	10730 3225 10730 3470
Wire Wire Line
	10830 2550 10830 3470
Wire Wire Line
	10730 2550 10895 2550
Wire Wire Line
	10730 2550 10730 2700
Connection ~ 10830 2550
Wire Wire Line
	10930 2670 10930 3470
Wire Wire Line
	11095 2550 11360 2550
Wire Wire Line
	14920 3740 14920 3810
Wire Wire Line
	14920 4110 14920 4220
Wire Wire Line
	14385 3740 14920 3740
Wire Wire Line
	14385 3930 14385 3740
Wire Wire Line
	12800 3930 14385 3930
Wire Wire Line
	12915 4030 14385 4030
Wire Wire Line
	14720 3960 14720 3605
Wire Wire Line
	15120 3960 15120 3605
Wire Wire Line
	14720 3605 15250 3605
Wire Wire Line
	14385 4030 14385 4220
Wire Wire Line
	14385 4220 14920 4220
Wire Wire Line
	14130 4340 14130 4430
Wire Wire Line
	14135 3620 14135 3460
Wire Wire Line
	14135 3460 14370 3460
Wire Wire Line
	14130 4430 14350 4430
Connection ~ 15120 3605
Wire Wire Line
	12530 4240 12800 4240
Wire Wire Line
	12800 4240 12800 3930
Wire Wire Line
	12915 4030 12915 4340
Wire Wire Line
	12915 4340 12530 4340
Wire Wire Line
	13040 4225 13230 4225
Wire Wire Line
	12530 4540 13155 4540
Wire Wire Line
	13155 4540 13155 4410
Wire Wire Line
	13155 4410 13230 4410
Wire Wire Line
	13040 4225 13040 4440
Wire Wire Line
	13040 4440 12530 4440
Wire Wire Line
	13430 4225 13580 4225
Wire Wire Line
	13580 4225 13580 4410
Wire Wire Line
	13580 4410 13430 4410
Wire Wire Line
	14135 3820 14135 3930
Connection ~ 14135 3930
Wire Wire Line
	14130 4140 14130 4030
Connection ~ 14130 4030
Wire Wire Line
	13580 4320 13685 4320
Connection ~ 13580 4320
Wire Wire Line
	12530 4740 13275 4740
Wire Wire Line
	13160 4845 13160 4740
Connection ~ 13160 4740
Wire Wire Line
	13160 5045 13160 5155
Wire Wire Line
	12530 4640 13035 4640
Wire Wire Line
	13160 5100 13035 5100
Wire Wire Line
	13035 5100 13035 4640
Connection ~ 13160 5100
Wire Wire Line
	11730 5940 11730 6040
Wire Wire Line
	11730 6040 11925 6040
Wire Wire Line
	12530 5140 12675 5140
Wire Wire Line
	12530 5240 12675 5240
Wire Wire Line
	11220 2550 11220 2670
Wire Wire Line
	11220 2670 10930 2670
Connection ~ 11220 2550
Wire Wire Line
	10730 2900 10730 3025
Wire Wire Line
	11925 6140 11630 6140
Wire Wire Line
	11630 6140 11630 5940
Wire Wire Line
	11925 6640 11130 6640
Wire Wire Line
	11130 6640 11130 5940
Wire Wire Line
	10830 5940 10830 6940
Wire Wire Line
	10830 6940 11925 6940
Wire Wire Line
	10730 5940 10730 7040
Wire Wire Line
	10730 7040 11925 7040
Wire Wire Line
	7070 5895 7070 6330
Wire Wire Line
	6940 5895 6940 6230
Wire Wire Line
	7280 4970 6990 4970
Wire Wire Line
	7280 5170 6985 5170
Wire Wire Line
	4715 2990 4525 2990
Wire Wire Line
	4715 3090 4525 3090
Wire Wire Line
	4525 3090 4525 3195
Wire Wire Line
	6890 6230 7175 6230
Wire Wire Line
	6895 6330 7175 6330
Wire Wire Line
	7140 3235 6970 3235
Wire Wire Line
	7140 3335 6970 3335
Wire Wire Line
	7140 3435 6970 3440
Wire Wire Line
	7140 3535 6970 3540
Wire Wire Line
	6970 3540 6970 3650
Wire Wire Line
	2555 4050 2425 4050
Wire Wire Line
	2555 4150 2425 4150
Wire Wire Line
	2425 4150 2425 4270
Wire Wire Line
	11925 6740 11035 6735
Wire Wire Line
	11035 6735 11030 5940
Wire Wire Line
	11925 6840 10940 6840
Wire Wire Line
	10940 6840 10930 5940
Wire Wire Line
	4060 4190 3790 4195
Wire Wire Line
	3790 4195 3790 4350
Wire Wire Line
	5015 4330 5165 4330
Wire Wire Line
	5650 4370 5650 4435
Wire Wire Line
	5090 4435 5090 4330
Connection ~ 5090 4330
Wire Wire Line
	5090 4635 5090 4715
Wire Wire Line
	14860 4740 14380 4740
Wire Wire Line
	13920 4740 14180 4740
Wire Wire Line
	14055 5060 14055 5135
Wire Wire Line
	7500 8415 7500 8115
Connection ~ 7500 8115
Connection ~ 6940 6230
Connection ~ 7070 6330
Wire Wire Line
	13720 4740 13475 4740
Wire Wire Line
	14055 4860 14055 4740
Connection ~ 14055 4740
Wire Wire Line
	5320 5895 5320 6110
Wire Wire Line
	5005 6010 5320 6010
Connection ~ 5320 6010
Wire Wire Line
	5320 6710 5320 6770
Wire Wire Line
	4255 5635 4255 5535
Wire Wire Line
	4255 5535 3940 5535
Wire Wire Line
	4255 5835 4255 6050
Wire Wire Line
	3940 5950 4255 5950
Connection ~ 4255 5950
Wire Wire Line
	4255 6650 4255 6710
Wire Wire Line
	3045 5585 3045 5485
Wire Wire Line
	3045 5485 2730 5485
Wire Wire Line
	3045 5785 3045 6000
Wire Wire Line
	2730 5900 3045 5900
Connection ~ 3045 5900
Wire Wire Line
	3045 6600 3045 6660
Wire Wire Line
	2320 3335 2320 3370
Wire Wire Line
	4060 4060 3960 4060
Wire Wire Line
	3960 4060 3960 3850
Wire Wire Line
	3895 3490 3965 3490
Wire Wire Line
	3965 3490 3960 3650
Wire Wire Line
	5780 4060 5020 4060
Wire Wire Line
	5650 4170 5650 4060
Connection ~ 5650 4060
Wire Wire Line
	2340 2860 2225 2860
Wire Wire Line
	2340 2825 2340 2860
$Comp
L PWR_FLAG #FLG028
U 1 1 5B2408BF
P 2340 2825
F 0 "#FLG028" H 2340 2900 50  0001 C CNN
F 1 "PWR_FLAG" H 2340 2975 50  0000 C CNN
F 2 "" H 2340 2825 50  0001 C CNN
F 3 "" H 2340 2825 50  0001 C CNN
	1    2340 2825
	1    0    0    -1  
$EndComp
Text GLabel 2225 2860 0    60   Input ~ 0
VBAT
$EndSCHEMATC
