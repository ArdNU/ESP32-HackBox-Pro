#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>
#include "../config.h"

struct DisplayData {
    float temperature;
    float humidity;
    float pressure;
    uint16_t packets_captured;
    uint16_t devices_found;
    bool attack_active;
};

class DisplayManager {
public:
    DisplayManager() {}
    
    void init() {
        // Initialize OLED display
        // Will be implemented with Adafruit SSD1306
    }
    
    void showSplash(const char* device_name, const char* version) {
        Serial.println("\n╔════════════════════════════════════════╗");
        Serial.print("║  ");
        Serial.print(device_name);
        Serial.println("  ║");
        Serial.print("║  Version: ");
        Serial.print(version);
        Serial.println("                  ║");
        Serial.println("║  ESP32-based Multi-tool  ║");
        Serial.println("╚════════════════════════════════════════╝\n");
    }
    
    void updateMain(const DisplayData& data, const AttackStats& stats) {
        // Update main display with sensor data and attack stats
    }
    
private:
};

struct AttackStats {
    uint16_t total_packets;
    uint16_t deauth_sent;
    uint16_t devices_deauthed;
};

#endif // DISPLAY_MANAGER_H
