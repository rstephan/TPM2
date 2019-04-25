# TPM2 Arduino library

TPM2 is a protocol designed for LED (matrices) communications.
Details about TPM2 can be found [here](https://www.ledstyles.de/index.php?thread/18969-tpm2-protokoll-zur-matrix-lichtsteuerung/) (german).
This is a generic Arduino implementation of the protocol, is uses the serial part only, also called TPM2.serial. It should work on any
Arduino.

If you are searching for network support, take a look at the alternatives below.

## Limitations

The amount of free RAM defines the number or LEDs. An Arduino Uno with 2 KiByte RAM can only handle a finite number of LEDs. Use a bigger Arduino (e.g. Mega 2560) for more LEDs.

## Installation

As usual, place this repository into the Arduino library folder,
e.g. `~/Documents/Arduino/libraries/` for macOS or `~/Arduino/libraries/` for Linux. Or use the [Arduino-IDE](https://www.arduino.cc/en/Guide/Libraries#toc4) to import the zip-file.

## Hardware

Smart LEDs like WS2812 (NeoPixels) or similar devices need a lot of current. In most cases 10 LEDs will exceed the capabilities of a USB 2 port.

Short example for 3-color (RGB) LEDs in full white.

|LED(s)|Current|
|-----:|------:|
|    1 |  60 mA|
|   10 | 600 mA|
|  100 |6000 mA|

WS2812 are 5 Volt LEDs, so driving the data-Pin with 5 V is necessary. In most cases 3.3 V will work, too. But that is not good engineering.
More details can be found in Adafruits [Best Practices](https://learn.adafruit.com/adafruit-neopixel-uberguide/best-practices) guide.

## Examples

### TPM2NeoPixel

TPM2 with Adafruit's [NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel).

### TPM2FastLED

TPM2 with the [FastLED library](https://github.com/FastLED/FastLED).

## PC Software support

* [JINX!](http://www.live-leds.de/downloads/)
* [GLEDiator](http://www.solderlab.de/index.php/software/glediator)

## Alternatives

* TPM2.net: TPM2 over UDP packets.
* Art-Net(tm): For example, my [ArtnetWifi](https://github.com/rstephan/ArtnetWifi) library.

## Commercial devices

* [LED-Player from led-genial.de](https://www.led-genial.de/LED-Player)

## License

GPL v2 only
