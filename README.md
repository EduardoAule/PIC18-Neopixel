# PIC18F4550 + Neopixel + CCS Compiler

Se muestra como utilizar un microcontrolador Microchip el mitico PIC18F4550 para el control de leds NEOPIXEL,
el uso de Neopixels no es exclucivo de la plataforma Arduino, a pesar de la gran cantidad de librerias que hay para su manejo,
no es realmente tan complicado de implementar en otro microcontrolador.

## Introduccion
El proyecto cuenta con 36 NEOPIXELS, dos botones, uno para cambiar la animacion de colores y otro para controlar
el brillo, permite ajustar el brillo en 5 niveles.
Los NEOPIXELS estan ordenados en forma triangular (figura mas abajo).
Los NEOPIXELS usados a pesar de que son RGB, el orden realmente de cada NEOPIXEL es GRB, tener cuidado como se envia estos
valores a cada NEOPIXEL.

    Nota: Para cada NEOPIXEL se usan 3 bytes, un byte por cada color G, R, B.

Para mas información sobre los Neopixel referirse a la Uberguide de Adafruit:

https://cdn-learn.adafruit.com/downloads/pdf/adafruit-neopixel-uberguide.pdf

"NeoPixel" es la marca de Adafruit para píxeles y tiras de color RGB con direcciones individuales basadas en los controladores 
LED WS2812, WS2811 y SK6812, utilizando un protocolo de control de un solo cable.
Para conocer el protocolo que manejan los NEOPIXEL:

https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf

## Requerimientos
El lenguaje usado es C proporcionado por el compilador CCS Compiler.
    
    * CCS Compiler v5.081, (testeado también con v4.13).

Diseño del esquema.
    
    * Proteus ISIS v8.

Fuente de Alimetacion.
    
    * Modulo LM2596 DC-DC Step-Down. Voltaje de entrada 12VDC con salida a 5VDC.

* Un Protoboard.

## Esquema
Se utilizan dos botones PULL-DOWN, el primer boton (btn1), cambia el modo de colores en los leds.
El segundo boton (btn2), cambia el brillo general de los NEOPIXELS.

![alt text](https://github.com/EduardoAule/PIC18-Neopixel/blob/master/PIC18_Neopixels.png)

## Codigo
La parte esensial del proyecto es la libreria Neopixel.c, la cual se encarga de enviar los valores RGB a la tira
de NEOPIXELS.
Los colores estan repartidos en tres arrays NeoGreen[NeoPixel], NeoRed[NeoPixel] y NeoBlue[NeoPixel], setear un color
a un NEOPIXEL significa asignar un valor en la misma posicion en esos tres arrays, la longitud de cada array es igual 
a la cantidad de NEOPIXELS usados, el cual se define como:

    #define NUM_PIXELS 36
    
La funcion:
    
    void NeoDraw (void)
    
se encarga de recorrer y leer cada valor para cada color en esos arrays.
La funcion:
    
    void NeoBit (int1 Bit)
    
se encarga de generar el "protocolo" poniendo un pin del PIC en estado alto o bajo de acuerdo al protocolo del chip WS2812B,
en este caso se escribe al puerto de forma directa, pin_E2 es el pin de datos usados para la tira de NEOPIXELS.

    #bit RE2=0xf84.2
    
Asi en lugar de usar las funciones:
  
     output_high(PIN_E2);
     output_low(PIN_E2);
    
las cuales consumen "más" tiempo en ejecutarse a nivel asm que escribir directamente al pin del puerto E,
esto da la posibilidad de que no sea necesario usar un microcontrolador a una alta frecuencia. Por ejemplo,
usar un PIC16 o PIC12 con un crystal de 20MHz podria funcionar.

Nota: EL PIC18F4550 usado en este proyecto funciona a una velocidad de 48 MHz, usando un postscaler
para llevar un crystal externo de 12 MHz hasta los 48MHz, por lo que ejecuta 12MIPS.

La idea de usar un PIC para el manejo de los NEOPIXELS surgio a partir de este video, con el plus de que agregue el
citado manejo del puerto.

https://www.youtube.com/watch?v=EXr2_zSfnFw

# English version
It shows how to use a Microchip microcontroller the mythical PIC18F4550 for the control of leds NEOPIXEL,
the use of Neopixels is not exclusive to the Arduino platform, despite the large number of libraries available for its use,
It's not really that complicated to implement in another microcontroller.

## Introduction
The project has 36 NEOPIXELS, two buttons, one to change the color animation and another to control
the brightness, allows to adjust the brightness in 5 levels.
The NEOPIXELS are arranged in triangular form (figure below).
The NEOPIXELS used although they are RGB, the actual order of each NEOPIXEL is GRB, be careful how you send these
values to each NEOPIXEL.

    Note: For each NEOPIXEL, 3 bytes are used, one byte for each color G, R, B.

For more information about the Neopixel refer to the Uberguide of Adafruit:

https://cdn-learn.adafruit.com/downloads/pdf/adafruit-neopixel-uberguide.pdf

"NeoPixel" is the Adafruit brand for pixels and RGB color strips with individual addresses based on the controllers
LED WS2812, WS2811 and SK6812, using a single cable control protocol.
To know the protocol that the NEOPIXELs handle:

https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf

## Requirements
The language used is C provided by the compiler CCS Compiler.
    
    * CCS Compiler v5.081, (also tested with v4.13).

Scheme design.
    
    * Proteus ISIS v8.

Source of Alimetacion.
    
    * Module LM2596 DC-DC Step-Down. 12VDC input voltage with 5VDC output.

* A Protoboard.

## Scheme
Two PULL-DOWN buttons are used, the first button (btn1), changes the color mode in the LEDs.
The second button (btn2), changes the general brightness of the NEOPIXELS.

! [alt text] (https://github.com/EduardoAule/PIC18-Neopixel/blob/master/PIC18_Neopixels.png)

## Code
The essential part of the project is the Neopixel.c library, which is responsible for sending the RGB values ​​to the strip
of NEOPIXELS.
The colors are divided into three arrays NeoGreen [NeoPixel], NeoRed [NeoPixel] and NeoBlue [NeoPixel], set a color
a NEOPIXEL means assigning a value in the same position in those three arrays, the length of each array is equal
to the amount of NEOPIXELS used, which is defined as:

    #define NUM_PIXELS 36
    
The function:
    
    void NeoDraw (void)
    
It is responsible for traversing and reading each value for each color in those arrays.
The function:
    
    void NeoBit (int1 Bit)
    
is responsible for generating the "protocol" by placing a PIC pin in high or low state according to the protocol of 
the WS2812B chip, in this case, the port is written directly, pin_E2 is the data pin used for the NEOPIXELS strip.

    #bit RE2 = 0xf84.2
    
So instead of using the functions:
  
     output_high (PIN_E2);
     output_low (PIN_E2);
    
which consume "more" time to run at the same level as writing directly to the pin of port E,
this gives the possibility that it is not necessary to use a microcontroller at a high frequency. For example,
using a PIC16 or PIC12 with a 20MHz crystal could work.

Note: The PIC18F4550 used in this project works at a speed of 48 MHz, using a postscaler
to carry an external crystal of 12 MHz up to 48MHz, so it runs 12MIPS.

The idea of using a PIC for the management of the NEOPIXELS emerged from this video, with my plus of port management.

https://www.youtube.com/watch?v=EXr2_zSfnFw
