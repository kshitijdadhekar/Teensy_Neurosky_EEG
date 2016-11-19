Open the Brain.cpp file
Teensy has 3 hardware serial ports, so you dont need to use the software serial Library on the Teensy
You can just go Serial1.begin Serial2.begin and so on!

Edit the 3rd line in the Brain.cpp file to the required Serial port you are using on the Teensy
Here i am using the Serial3 port on the Teensy LC which is on Pin 7,8 

#define btSerial Serial3

