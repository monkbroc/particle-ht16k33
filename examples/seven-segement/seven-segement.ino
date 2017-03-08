// Drive a sevent segement LED using a HT16K33

#include "HT16K33.h"

const uint8_t NUMBER_CODES[10] = {
    0x7D, // 0
    0x11, // 1
    0xDC, // 2
    0xD9, // 3
    0xB1, // 4
    0xE9, // 5
    0xED, // 6
    0x19, // 7
    0xFD, // 8
    0xF9, // 9
};

HT16K33 driver;
int number = 0;

void setup() {
    driver.begin();
    driver.setBrightness(9);
}

void loop() {
    uint8_t codes[2];
    code[0] = NUMBER_CODES[number / 10];
    code[1] = NUMBER_CODES[number % 10];
    driver.writeDisplay(codes, 0, sizeof(codes));
    number++;
    if (number >= 100) {
        number = 0;
    }
    delay(250);
}
