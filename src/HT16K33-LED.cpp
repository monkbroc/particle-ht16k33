/*
 * HT16K33 LED driver library by Julien Vanier <jvanier@gmail.com>
 */

#include "HT16K33-LED.h"

const uint8_t HT16K33::BASE_SLAVE_ADDRESS = 0x70;

const uint8_t HT16K33::COMMAND_ON = 0x21;
const uint8_t HT16K33::COMMAND_STANDBY = 0x20;

const uint8_t HT16K33::COMMAND_DISPLAY_ON = 0x81;
const uint8_t HT16K33::COMMAND_DISPLAY_OFF = 0x80;
const uint8_t HT16K33::COMMAND_BRIGHTNESS = 0xE0;

const uint8_t HT16K33::MAX_BRIGHTNESS = 15;
const uint8_t HT16K33::DEFAULT_BRIGHTNESS = 8;

void HT16K33::begin(uint8_t deviceNumber) {
    // Allow chip to finish reset cycle
    delay(1);

    this->i2cAddress = BASE_SLAVE_ADDRESS + deviceNumber;
    
    Wire.begin();
    
    this->writeCommand(COMMAND_ON);
    this->writeCommand(COMMAND_DISPLAY_ON);
    this->setBrightness(DEFAULT_BRIGHTNESS);
}

void HT16K33::setBrightness(uint8_t brightness) {
    if(brightness > MAX_BRIGHTNESS) {
        brightness = MAX_BRIGHTNESS;
    }
    this->writeCommand(COMMAND_BRIGHTNESS + brightness);
}

void HT16K33::writeCommand(uint8_t command) {
    Wire.beginTransmission(this->i2cAddress);
    Wire.write(command);
    Wire.endTransmission();
}


void HT16K33::writeByte(uint8_t address, uint8_t data) {
    Wire.beginTransmission(this->i2cAddress);
    Wire.write(address);
    Wire.write(data);
    Wire.endTransmission();
}

void HT16K33::writeDisplay(uint8_t data[], uint8_t start, uint8_t length) {
    Wire.beginTransmission(this->i2cAddress);
    Wire.write(start);
    for(uint8_t i = 0; i < length; i++) {
        Wire.write(data[i]);
    }
    Wire.endTransmission();
}
