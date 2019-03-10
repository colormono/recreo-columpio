# COLUMPIO

![Columpio v1](./docs/render-columpio-01.jpg)

Columpio con giroscopios acelerómetro que modifica un cuadro.
El cuadro puede ser sólo lumínico, que se ilumine al recibir movimiento.
El columpio es inclusivo, adjunto referencia.

Instalación interactiva compuesta por dos objetos.
Sobre el piso un columpio construido con madera, metal y caucho.
Sobre la pared un cajón luminoso hace de marco a una media esfera.
El movimiento del columpio altera la iluminación del cajón mediante el uso de componentes electrónicos.

Columpio trata sobre esparcimiento y memoria. Un mecanismo que invita a participar y que reacciona a consecuencia; que almacena momentos de colaboración y los rememora en tiempos de soledad. Realizada con herramientas propias de las artes multimediales pretende evidenciar la proximidad de estas con los conceptos de generatividad y tiempo.

La estructura del columpio es de madera y los soportes de las esquinas de metal, al igual que las cadenas que sostienen al asiento de caucho. Debajo de asiento se encuentra un sensor acelerómetro y giroscopio conectados a un microcontrolador NODEMCU que envía la actividad registrada vía WIFI al soporte lumínico que se encuentra montado sobre la pared. Este circuito es alimentado por una batería de Litio.

El cajón está construido con madera MDF y una semi esfera de tergopol, todo pintado de blanco satinado. En los cuatro bordes interiores, invisibles al espectador, se encuentran adheridas tiras de led RGB que permiten controlar cada led individualmente. La información para cada led es enviada por un microcontrolador arduino uno y este a su vez es alimentado por una raspberry pi 3 que es quién se encarga de la comunicación con el columpio y el almacenamiento en memoria de la actividad.

**[Documentación API](#nombre)**

## Electrónica

### Leds

Estoy utilizando una tira de les WS2812B con 60 leds por metro.
Esta tiene la particularidad de permitir el control individual de los leds.
Para desarrollar elegí la librería [FastLED](https://github.com/FastLED/FastLED) porque funciona con varios modelos de tiras de led, está bien documentada, permite usar el [modelo de color HSV](http://en.wikipedia.org/wiki/HSL_and_HSV) y cuenta con transiciones vía [operaciones matemáticas](https://github.com/FastLED/FastLED/wiki/High-performance-math).

#### Circuito básico, "Hello leds":

![Led Circuit](./docs/leds-circuit.png)

```c
/**
   Led Stripe testing

   I'm using the WS2812B with 60 leds per meter
   This led stripe has 3 wires
   White (GND): to Ground POWER and to Arduino GND
   Red (VCC): to 5v POWER and to Arduino 5v if this is not connected via USB
   Green (DATA): to ARDUINO LED_PIN (digital or ~ is the same)
   Note: If you are not using an external power source change the NUM_LEDS to less than 10.
*/
#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    60
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(40);
  }
  for (int i = NUM_LEDS; i >= 0; i--) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(40);
  }
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB ( 0, 255, 0);
    FastLED.show();
    delay(40);
  }
  for (int i = NUM_LEDS; i >= 0; i--) {
    leds[i] = CRGB ( 255, 0, 255);
    FastLED.show();
    delay(40);
  }
}
```

#### Links útiles

- [FastLed Library](https://github.com/FastLED/FastLED): Librería para controlar los leds
- [FastLed Documentation](https://github.com/FastLED/FastLED/wiki/Overview): Documentación de la librería
- [FastLed read data from serial](https://github.com/FastLED/FastLED/wiki/Controlling-leds#read-rgb-data-from-serial): Leer información vía serial
- [FastLed Community](https://github.com/FastLED/FastLED): Comunidad de la librería
- [Tutorial para controlar leds individualmente](https://howtomechatronics.com/tutorials/arduino/how-to-control-ws2812b-individually-addressable-leds-using-arduino/)
- [Alimentar tira de led con fuente de PC](https://www.youtube.com/watch?v=srJgt85cUMY)
- [FastLED Palette Knife Demo](https://www.youtube.com/watch?v=7CDgxgyALWQ)

### Giroscopio

Aceleración y acelerómetros
La aceleración es la variación de la velocidad por unidad de tiempo es decir razón de cambio en la velocidad respecto al tiempo:

**a=dV/dt**

Así mismo la segunda ley de Newton indica que en un cuerpo con masa constante, la aceleración del cuerpo es proporcional a la fuerza que actúa sobre él mismo:

**a=F/m**

Este segundo concepto es utilizado por los acelerómetros para medir la aceleración. Los acelerómetros internamente tienen un MEMS(MicroElectroMechanical Systems) que de forma similar a un sistema masa resorte permite medir la aceleración.

Con un acelerómetro podemos medir esta aceleración, teniendo en cuenta que a pesar que no exista movimiento, siempre el acelerómetro estará sensando la aceleración de la gravedad.

Con el acelerómetro podemos hacer mediciones indirectas como por ejemplo si integramos la aceleración en el tiempo tenemos la velocidad y si la integramos nuevamente tenemos el desplazamiento, necesitando en ambos casos la velocidad y la posición inicial respectivamente.

### Comunicación WiFi

## Link a su apartado en la documentación

## Diagramas

## Circuito

## Memoria

## Bibliografía

- Socket.IO Real-time Web Application Development, Rohit Rai. Packtpub, 2013.

## Enlaces útiles

- [Librería para los leds](https://github.com/FastLED/FastLED)
- [Tutorial para los leds](https://howtomechatronics.com/tutorials/arduino/how-to-control-ws2812b-individually-addressable-leds-using-arduino/)
- [Alimentar tira de led con fuente de PC](https://www.youtube.com/watch?v=srJgt85cUMY)

- [Tutorial MPU6050, Acelerómetro y Giroscopio](https://naylampmechatronics.com/blog/45_Tutorial-MPU6050-Aceler%C3%B3metro-y-Giroscopio.html)

- [Arduino Wireless Communication – NRF24L01 Tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/)
- [Tutorial básico NRF24L01 con Arduino](https://naylampmechatronics.com/blog/16_Tutorial-b%C3%A1sico-NRF24L01-con-Arduino.html)

- [Usando ESP8266 con el IDE de Arduino](https://naylampmechatronics.com/blog/56_usando-esp8266-con-el-ide-de-arduino.html)
- Qué son los Websockets? (adaptar resumen desde acá https://youtu.be/lcJzVP20McM?t=3m4s)
