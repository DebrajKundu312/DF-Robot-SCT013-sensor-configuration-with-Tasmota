# DF-Robot-SCT013-sensor-configuration-with-Tasmota
The settings and configuration of the Tasmota firmware to support the CT Non-invasive current sensor to send data through mqtt and web interface.

Module parameter 
Connecting the SCT013 to the ADS1115
1- K wire to A0 of the ADC.
2- L wire to A1 of the ADC.

Connecting the ADS1115 to ESP
1- VCC to 3.3v.
2- GND(ADS1115) to GND(ESP) and ADDR(ADS1115) to GND(ESP).
3- SDA to GPIO4.
4- SCL to GPIO0.

Firstly set the Wifi network configuration 
SSID 1
Password 1
SSID 2
Password 2


Created a firware support named xsns_116_sct013.ino 

Modified user_config_override.h
line 90

Modified my_user_config.h
line 606
