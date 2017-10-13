#include <SPI.h>
#include "FXOS8700CQ.h"

FXOS8700CQ sensor;
#define LED_RGB_RED 6
#define LED_RGB_GREEN 7
#define LED_RGB_BLUE 8

void setup() {
   Initialize SerialUSB 
  SerialUSB.begin(9600);
  while(!SerialUSB);
  //init LED pins
//  pinMode(LED_RGB_RED, OUTPUT);
//  pinMode(LED_RGB_GREEN, OUTPUT);
//  pinMode(LED_RGB_BLUE, OUTPUT);
//  //turn off all LEDs
//  digitalWrite(LED_RGB_BLUE, LOW);
//  digitalWrite(LED_RGB_GREEN, LOW);
//  digitalWrite(LED_RGB_RED, LOW);
  // Initialize SPI
  SPI.begin();

  // Initialize sensor
  sensor = FXOS8700CQ();
  sensor.init();

  sensor.checkWhoAmI();
  // TODO: Check the sensor's WhoAmI value
  if (sensor.whoAmIData != FXOS8700CQ_WHOAMI_VAL){
    SerialUSB.println ("SPI_WhoAmI_ERROR");
  }
  
}

void loop() {
  // TO DO: Read Mag data. Get all parameters 
  sensor.readMagData();
  SerialUSB.print("magX: "); 
  SerialUSB.println(sensor.magData.x);
  SerialUSB.print("magY: ");
  SerialUSB.println(sensor.magData.y);
  SerialUSB.print("magZ: " );
  SerialUSB.println(sensor.magData.z);
  delay(500);

//code used for comparing power comsumption with I2C on PowrDue board  
//  for (int i = 10000; i>=0;i--){
//  sensor.checkWhoAmI();
 // }
//  SerialUSB.println("turn on the LED"); 
 // digitalWrite(LED_RGB_BLUE, HIGH);
 // delay(1000);
 // digitalWrite(LED_RGB_BLUE, LOW);
//  SerialUSB.println("turn off the LED");
}
