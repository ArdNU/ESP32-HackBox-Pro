#ifndef ACTUATOR_MANAGER_H
#define ACTUATOR_MANAGER_H

#include <Arduino.h>
#include "../config.h"

class ActuatorManager {
public:
    ActuatorManager() {}
    
    void init() {
        if (ENABLE_BUZZER) {
            pinMode(BUZZER_PIN, OUTPUT);
            digitalWrite(BUZZER_PIN, LOW);
        }
        
        if (ENABLE_LED) {
            pinMode(LED_PIN, OUTPUT);
            digitalWrite(LED_PIN, LOW);
        }
        
        if (ENABLE_RELAY) {
            pinMode(RELAY_PIN, OUTPUT);
            digitalWrite(RELAY_PIN, LOW);
        }
        
        if (ENABLE_SERVO) {
            // Initialize servo
        }
    }
    
    void beep(uint8_t times = 1, uint16_t duration = 100) {
        if (!ENABLE_BUZZER) return;
        for (int i = 0; i < times; i++) {
            digitalWrite(BUZZER_PIN, HIGH);
            delay(duration);
            digitalWrite(BUZZER_PIN, LOW);
            if (i < times - 1) delay(duration);
        }
    }
    
    void setLED(bool state) {
        if (!ENABLE_LED) return;
        digitalWrite(LED_PIN, state ? HIGH : LOW);
    }
    
    void setRelay(bool state) {
        if (!ENABLE_RELAY) return;
        digitalWrite(RELAY_PIN, state ? HIGH : LOW);
    }
    
    void blinkLED(uint8_t times, uint16_t duration) {
        if (!ENABLE_LED) return;
        for (int i = 0; i < times; i++) {
            digitalWrite(LED_PIN, HIGH);
            delay(duration);
            digitalWrite(LED_PIN, LOW);
            delay(duration);
        }
    }
    
private:
};

#endif // ACTUATOR_MANAGER_H
