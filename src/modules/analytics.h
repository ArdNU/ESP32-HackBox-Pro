#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <Arduino.h>
#include "../config.h"
#include "sensor_manager.h"

class Analytics {
public:
    Analytics() {}
    
    void init() {
        // Initialize analytics storage
    }
    
    void logReading(const SensorData& data) {
        // Log sensor data for analytics
    }
    
    void logAttack(const char* attack_type, uint16_t packets) {
        // Log attack statistics
    }
    
private:
};

#endif // ANALYTICS_H
