#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int msg[1];
RF24 radio(9, 10);
const byte address[6] = "00001";
int LED1 = 13;

void setup(void) {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.startListening();
  pinMode(LED1, OUTPUT);
}

void loop(void) {
  if (radio.available()) {
      Serial.println(msg[0]);
      if (msg[0] == 111) {
        delay(10);
        digitalWrite(LED1, HIGH);
      }
      else {
        digitalWrite(LED1, LOW);
      }
      delay(10);
  }
  else {
    Serial.println("No radio available");
  }
}
