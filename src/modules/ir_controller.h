#ifndef IR_CONTROLLER_H
#define IR_CONTROLLER_H

#include <Arduino.h>
#include "../config.h"

struct IRCode {
    uint32_t code;
    uint8_t bits;
    const char* device;
    const char* action;
};

class IRController {
public:
    IRController() {}
    
    void init() {
        if (ENABLE_IR_CONTROL) {
            pinMode(IR_TX_PIN, OUTPUT);
            pinMode(IR_RX_PIN, INPUT);
        }
    }
    
    // Send IR code
    void sendCode(uint32_t code, uint8_t bits) {
        if (!ENABLE_IR_CONTROL) return;
        // Implementation for IR transmission
    }
    
    // Learn IR code (receive and store)
    bool learnCode(IRCode& code, uint16_t timeout) {
        if (!ENABLE_IR_LEARNING) return false;
        // Implementation for IR learning
        return false;
    }
    
    // Control common devices
    void acOn() { sendCode(0xFF30CF, 32); }      // Universal AC ON
    void acOff() { sendCode(0xFF38C7, 32); }     // Universal AC OFF
    void tvPower() { sendCode(0xFF02FD, 32); }   // Universal TV Power
    void tvVolUp() { sendCode(0xFF18E7, 32); }   // Universal TV Vol+
    void tvVolDown() { sendCode(0xFF4AB5, 32); } // Universal TV Vol-
    
private:
};

#endif // IR_CONTROLLER_H
