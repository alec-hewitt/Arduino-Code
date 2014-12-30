/*
-Reads analog values over A0 and A1
-Transmits values over a nRF24LO1 radio link to another receiver
Connections:
  -
  Receiver:
  1 - GND
  2 - VCC - 3.3V NOT 5V
  3 - CE - IO pin 9
  4 - CSN - IO pin 10
  5 - SCK - IO pin 13
  6 - MOSI - IO pin 11
  7 - MISO - IO pin 12
  8 - unused
  -
  Joystick:
  GND - Arduino GND
  VCC - Arduino +5V
  X pot - Arduino A0
  Y pot - Arduino A1

*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

//connection definitions
#define CE_PIN 9
#define CSN_PIN 10
#define ANALOG1 A0
#define ANALOG2 A1

//defines the transmit pipe
const uint64_t pipe = 0xE8E8F0F0E1LL;

//creates a radio
RF24 radio(CE_PIN, CSN_PIN);

//integer array to hold joystick readings
int analog_data[2];

void setup(){
  Serial.begin(9600);
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  //start radio
  radio.begin();
  //open pipeline for data reception
  radio.openReadingPipe(1, pipe);
  //listen for data
  radio.startListening();
}

void loop(){
  //check if radio is available
  if(radio.available()){
    //read all data
    bool done = false;
    while(!done){
      //fetch data
      done = radio.read(analog_data, sizeof(analog_data));
      //debug print data
      Serial.print("analog 1 data = ");
      Serial.print(analog_data[0]);
      Serial.print("analog 2 data = ");
      Serial.print(analog_data[1]);
    }
  } else { //if radio is not available
     Serial.print("No radio available"); 
  }
}
