/**
   Columpio Sensor v0.1
   by COLORMONO

   - Lectura acelerómetro y girsocopio
   - Wireless Communication

*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"


// --- CONFIG ---

// Config: Wifi
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";


// --- INPUTS ---

// Input: Acelerometro
MPU6050 sensor;
int ax, ay, az;
int gx, gy, gz;
void getSensorData();
float getAccData();

float accX;


// --- OUTPUTS ---

// Output: Leds


// --- SETUP ---

void setup() {
  Serial.begin(57600);

  // Wifi
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  //Iniciando I2C y sensor
  Wire.begin();
  sensor.initialize();
  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");

  // Calibrate
  // reset offsets
  //Sensor readings with offsets:  -17 2 16384 0 1 1
  //Your offsets: -3203 -5491 1506  -4  22  -15
  //Data is printed as: acelX acelY acelZ giroX giroY giroZ
  sensor.setXAccelOffset(-3203);
  sensor.setYAccelOffset(-5491);
  sensor.setZAccelOffset(1506);
  sensor.setXGyroOffset(-4);
  sensor.setYGyroOffset(22);
  sensor.setZGyroOffset(-15);
}

// --- LOOP ---

void loop() {
  //const char text[] = "Hello World 2";

  accX = getAccData();
  radio.write(&accX, sizeof(accX));

  //delay(100);
}
