# HT16K33-LED

A Particle library for the HT16K33 LED display driver.

## Usage

Connect the HT16K33 to I2C, add the HT16K33 library to your project and follow this simple example:

```
#include "HT16K33-LED.h"

HT16K33 display;

void setup() {
  display.begin();
}

void loop() {
  uint8_t dots[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  // Set dots[0], dots[1], etc to other values
  display.writeDisplay(dots, 0, sizeof(dots));
}
```

See the [examples](examples) folder for more details.

## Documentation

### `HT16K33`

TODO

## References

- [HT16K33 datasheet](https://cdn-shop.adafruit.com/datasheets/ht16K33v110.pdf)

## License
Copyright 2017 Julien Vanier

Released under the MIT license
