/**
   Columpio Emisor v01
   by COLORMONO

   - Lectura acelerómetro y girsocopio
*/
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

// --- CONFIG ---

// Config: Server



// --- INPUTS ---

// Input: Acelerometro
MPU6050 sensor;
int ax, ay, az;
int gx, gy, gz;
void getSensorData();
void getAccData();


// --- OUTPUTS ---

// Output: Leds


// --- SETUP ---

void setup() {
  Serial.begin(57600);

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
  getAccData();
  delay(100);
}
