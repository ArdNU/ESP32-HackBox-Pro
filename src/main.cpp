#include <Arduino.h>
#include "config.h"
#include "secrets.h"
#include "modules/logger.h"
#include "modules/display_manager.h"
#include "modules/wifi_sniffer.h"
#include "modules/sensor_manager.h"
#include "modules/actuator_manager.h"
#include "modules/ir_controller.h"
#include "modules/web_server.h"
#include "modules/bluetooth_manager.h"
#include "modules/network_attacks.h"
#include "modules/analytics.h"

// Global instances
Logger logger;
DisplayManager display;
WiFiSniffer sniffer;
SensorManager sensors;
ActuatorManager actuators;
IRController ir_ctrl;
WebServer web;
BluetoothManager bt;
NetworkAttacks attacks;
Analytics analytics;

unsigned long last_update = 0;
const unsigned long UPDATE_INTERVAL = 1000;  // 1 second

void setup() {
    Serial.begin(SERIAL_BAUD);
    delay(1000);
    
    logger.info("Starting %s v%s", DEVICE_NAME, FIRMWARE_VERSION);
    logger.info("Device ID: %s", DEVICE_ID);
    
    // Initialize display
    if (ENABLE_DISPLAY) {
        display.init();
        display.showSplash(DEVICE_NAME, FIRMWARE_VERSION);
        logger.info("Display initialized");
    }
    
    // Initialize sensors
    if (ENABLE_DHT || ENABLE_BMP280 || ENABLE_MPU6050 || ENABLE_GPS) {
        sensors.init();
        logger.info("Sensors initialized");
    }
    
    // Initialize actuators
    if (ENABLE_LED || ENABLE_BUZZER || ENABLE_RELAY) {
        actuators.init();
        logger.info("Actuators initialized");
    }
    
    // Initialize IR controller
    if (ENABLE_IR_CONTROL) {
        ir_ctrl.init();
        logger.info("IR Controller initialized");
    }
    
    // Initialize WiFi
    if (WIFI_MODE_AP) {
        WiFi.mode(WIFI_AP);
        WiFi.softAP(WIFI_AP_SSID, WIFI_AP_PASSWORD, WIFI_AP_CHANNEL, WIFI_AP_HIDDEN);
        logger.info("WiFi AP started: %s", WIFI_AP_SSID);
        logger.info("IP: %s", WiFi.softAPIP().toString().c_str());
    } else {
        WiFi.mode(WIFI_STA);
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        logger.info("Connecting to WiFi: %s", WIFI_SSID);
        
        int attempts = 0;
        while (WiFi.status() != WL_CONNECTED && attempts < 20) {
            delay(500);
            Serial.print(".");
            attempts++;
        }
        
        if (WiFi.isConnected()) {
            logger.info("WiFi connected! IP: %s", WiFi.localIP().toString().c_str());
        } else {
            logger.error("WiFi connection failed!");
        }
    }
    
    // Initialize Bluetooth
    if (ENABLE_BLE) {
        bt.initBLE();
        logger.info("BLE initialized");
    }
    
    // Initialize Web Server
    if (ENABLE_WEBSERVER) {
        web.init();
        logger.info("Web server started on port %d", WEBSERVER_PORT);
    }
    
    // Initialize WiFi Sniffer
    if (ENABLE_WIFI_SNIFFER) {
        sniffer.init();
        logger.info("WiFi Sniffer initialized");
    }
    
    // Initialize Network Attacks
    if (ENABLE_DEAUTH_ATTACK || ENABLE_MITM_ATTACK) {
        attacks.init();
        logger.info("Network attacks module initialized");
    }
    
    // Initialize Analytics
    analytics.init();
    logger.info("Analytics initialized");
    
    logger.info("=== Setup Complete ===");
    actuators.beep(2);  // Double beep to indicate ready
}

void loop() {
    unsigned long now = millis();
    
    // Update sensors periodically
    if (now - last_update >= UPDATE_INTERVAL) {
        last_update = now;
        
        // Read sensor data
        SensorData data = sensors.readAll();
        
        // Update display
        if (ENABLE_DISPLAY) {
            display.updateMain(data, attacks.getStats());
        }
        
        // Log important data
        if (DEBUG_MODE) {
            logger.debug("Temp: %.1f°C, Humidity: %.1f%%, Press: %.1f hPa",
                        data.temperature, data.humidity, data.pressure);
        }
        
        // Track analytics
        analytics.logReading(data);
    }
    
    // Handle WiFi sniffer
    if (ENABLE_WIFI_SNIFFER) {
        sniffer.update();
    }
    
    // Handle network attacks
    if (ENABLE_DEAUTH_ATTACK || ENABLE_MITM_ATTACK) {
        attacks.update();
    }
    
    // Handle web server
    if (ENABLE_WEBSERVER) {
        web.handleClient();
    }
    
    // Handle Bluetooth
    if (ENABLE_BLE) {
        bt.update();
    }
    
    // Small delay to prevent watchdog trigger
    delay(10);
}
