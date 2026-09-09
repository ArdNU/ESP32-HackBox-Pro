#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Arduino.h>
#include "../config.h"

struct SensorData {
    float temperature;
    float humidity;
    float pressure;
    float altitude;
    float gas_resistance;
    
    float accel_x, accel_y, accel_z;
    float gyro_x, gyro_y, gyro_z;
    float mag_x, mag_y, mag_z;
    
    float latitude;
    float longitude;
    float gps_altitude;
    
    uint16_t light_level;
    uint16_t battery_voltage;
};

class SensorManager {
public:
    SensorManager() {}
    
    void init() {
        // Initialize all sensors based on config
    }
    
    SensorData readAll() {
        SensorData data = {};
        
        // Read DHT
        if (ENABLE_DHT) {
            // data.temperature = dht.readTemperature();
            // data.humidity = dht.readHumidity();
        }
        
        // Read BMP280
        if (ENABLE_BMP280) {
            // data.pressure = bmp.readPressure();
            // data.altitude = bmp.readAltitude();
        }
        
        // Read MPU6050
        if (ENABLE_MPU6050) {
            // Read accelerometer and gyroscope
        }
        
        // Read GPS
        if (ENABLE_GPS) {
            // Read latitude and longitude
        }
        
        // Read light sensor
        if (ENABLE_LIGHT_SENSOR) {
            data.light_level = analogRead(LIGHT_SENSOR_PIN);
        }
        
        // Read battery
        if (ENABLE_BATTERY_MONITOR) {
            data.battery_voltage = analogRead(BATTERY_PIN) * 2;  // Voltage divider
        }
        
        return data;
    }
    
private:
};

#endif // SENSOR_MANAGER_H
