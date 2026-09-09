#ifndef CONFIG_H
#define CONFIG_H

// ============= DEVICE SETTINGS =============
#define DEVICE_NAME "ESP32-HackBox-Pro"
#define FIRMWARE_VERSION "1.0.0"
#define DEVICE_ID "HACK-001"

// ============= WIFI SETTINGS =============
#define WIFI_SSID "HackBox-Network"
#define WIFI_PASSWORD "HackBox2024"
#define WIFI_MODE_AP 1  // 0 = Client, 1 = AP (Access Point)
#define WIFI_AP_SSID "ESP32-HackBox"
#define WIFI_AP_PASSWORD "HackBox123"
#define WIFI_AP_CHANNEL 6
#define WIFI_AP_HIDDEN 0  // 0 = visible, 1 = hidden

// ============= NETWORK ATTACK SETTINGS =============
#define ENABLE_WIFI_SNIFFER 1
#define ENABLE_DEAUTH_ATTACK 1
#define ENABLE_MITM_ATTACK 1
#define ENABLE_DNS_SPOOFING 1
#define ENABLE_ARP_SPOOFING 1
#define ENABLE_PORT_SCAN 1
#define SNIFFER_CHANNEL 1
#define MAX_CAPTURED_PACKETS 1000

// ============= IR CONTROL SETTINGS =============
#define IR_TX_PIN 12
#define IR_RX_PIN 14
#define ENABLE_IR_CONTROL 1
#define ENABLE_IR_LEARNING 1

// ============= SENSOR SETTINGS =============
#define DHT_PIN 13
#define DHT_TYPE DHT22
#define ENABLE_DHT 1

#define BMP_SDA 21
#define BMP_SCL 22
#define ENABLE_BMP280 1
#define ENABLE_BME680 1

#define MPU_SDA 21
#define MPU_SCL 22
#define ENABLE_MPU6050 1

#define GPS_RX 16
#define GPS_TX 17
#define GPS_BAUD 9600
#define ENABLE_GPS 1

#define RFID_CS 5
#define RFID_MOSI 23
#define RFID_MISO 19
#define RFID_CLK 18
#define ENABLE_RFID 1

#define LIGHT_SENSOR_PIN 35  // ADC
#define ENABLE_LIGHT_SENSOR 1

#define MIC_PIN 32  // I2S or ADC
#define ENABLE_MICROPHONE 1

// ============= ACTUATOR SETTINGS =============
#define LED_PIN 2
#define LED_COUNT 1
#define ENABLE_LED 1

#define BUZZER_PIN 15
#define ENABLE_BUZZER 1

#define RELAY_PIN 27
#define ENABLE_RELAY 1

#define SERVO_PIN 26
#define ENABLE_SERVO 1

// ============= DISPLAY SETTINGS =============
#define DISPLAY_SDA 21
#define DISPLAY_SCL 22
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64
#define ENABLE_DISPLAY 1
#define DISPLAY_FLIP 0

// ============= LOGGING SETTINGS =============
#define ENABLE_LOGGING 1
#define LOG_LEVEL 2  // 0=DEBUG, 1=INFO, 2=WARN, 3=ERROR
#define MAX_LOG_SIZE 100000
#define LOG_TO_EEPROM 1
#define LOG_TO_SD 1

// ============= SD CARD SETTINGS =============
#define SD_CS 4
#define SD_SPI_FREQUENCY 1000000
#define ENABLE_SD 1

// ============= WEBSERVER SETTINGS =============
#define WEBSERVER_PORT 80
#define ENABLE_WEBSERVER 1
#define ENABLE_WEBSOCKET 1
#define MAX_WS_CLIENTS 5

// ============= BLUETOOTH SETTINGS =============
#define ENABLE_BLE 1
#define ENABLE_CLASSIC_BT 1
#define BT_DEVICE_NAME "ESP32-HackBox"

// ============= POWER SETTINGS =============
#define BATTERY_PIN 34  // ADC
#define ENABLE_BATTERY_MONITOR 1
#define SLEEP_MODE 0  // 0 = always on, 1 = deep sleep
#define SLEEP_TIMEOUT 600000  // 10 minutes in ms

// ============= DEBUG SETTINGS =============
#define DEBUG_MODE 1
#define SERIAL_BAUD 115200
#define ENABLE_OTA 1

#endif // CONFIG_H
