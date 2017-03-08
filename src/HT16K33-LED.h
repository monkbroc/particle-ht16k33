#pragma once

/*
 * HT16K33 LED driver library by Julien Vanier <jvanier@gmail.com>
 */

// This will load the definition for common Particle variable types
#include "Particle.h"

class HT16K33 {
    public:
    
    void begin(uint8_t deviceNumber = 0);
    void setBrightness(uint8_t brightness = DEFAULT_BRIGHTNESS);
    
    static const uint8_t MAX_BRIGHTNESS;
    static const uint8_t DEFAULT_BRIGHTNESS;
    
    void writeByte(uint8_t address, uint8_t data);
    void writeDisplay(uint8_t data[], uint8_t start, uint8_t length);    
    
    // Low-level interface
    
    void writeCommand(uint8_t command);
    
    static const uint8_t COMMAND_ON;
    static const uint8_t COMMAND_STANDBY;
    static const uint8_t COMMAND_DISPLAY_ON;
    static const uint8_t COMMAND_DISPLAY_OFF;
    static const uint8_t COMMAND_BRIGHTNESS;

    private:
    
    static const uint8_t BASE_SLAVE_ADDRESS;
    uint8_t i2cAddress;
    
};


#endif // __HT16K33_H__

