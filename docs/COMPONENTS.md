# Hardware Components Guide

## Main Controller

### ESP32 DevKit
- **Specification**: Dual-core CPU, 4MB Flash, 520KB RAM
- **Operating Voltage**: 3.3V
- **GPIO Pins**: 34 available
- **Connectivity**: WiFi 802.11 b/g/n, Bluetooth 4.2
- **Cost**: ~$10-15 USD

## Sensors

### DHT22 - Temperature & Humidity
- **Pin**: GPIO 13 (configurable)
- **Protocol**: 1-Wire
- **Range**: -40 to 125°C
- **Accuracy**: ±0.5°C
- **Cost**: ~$3 USD

### BMP280 - Pressure & Altitude
- **Interface**: I2C (SDA: 21, SCL: 22)
- **Range**: 300-1100 hPa
- **Accuracy**: ±1 hPa
- **Cost**: ~$3-5 USD

### BME680 - Environmental Sensor
- **Interface**: I2C/SPI (I2C: 21, 22)
- **Measures**: Temperature, Humidity, Pressure, Gas
- **Cost**: ~$15-20 USD

### MPU6050 - Accelerometer & Gyroscope
- **Interface**: I2C (SDA: 21, SCL: 22)
- **6-Axis IMU**: 3-axis accel + 3-axis gyro
- **Cost**: ~$5 USD

### NEO-6M - GPS Module
- **Interface**: Serial (RX: 16, TX: 17)
- **Baud Rate**: 9600 bps
- **Accuracy**: ±2.5 meters
- **Cost**: ~$10-15 USD

### RC522 - NFC/RFID Reader
- **Interface**: SPI (CS: 5, MOSI: 23, MISO: 19, CLK: 18)
- **Frequency**: 13.56 MHz
- **Range**: ~5 cm
- **Cost**: ~$3-5 USD

### BH1750 - Light Sensor
- **Interface**: I2C (SDA: 21, SCL: 22)
- **Range**: 1-65535 lux
- **Cost**: ~$2 USD

### Microphone (INMP441)
- **Interface**: I2S
- **Sampling Rate**: 16 kHz
- **Cost**: ~$5-8 USD

## Actuators

### WS2812B RGB LED Strip
- **Pin**: GPIO 2
- **Protocol**: 1-Wire
- **Voltage**: 5V
- **Cost**: ~$2-5 USD per meter

### Active Buzzer
- **Pin**: GPIO 15
- **Voltage**: 5V
- **Frequency**: 2-4 kHz
- **Cost**: ~$1 USD

### Relay Module (5V)
- **Pin**: GPIO 27
- **Max Current**: 10A at 250V AC
- **Cost**: ~$1-2 USD

### SG90 Servo Motor
- **Pin**: GPIO 26
- **Voltage**: 5V
- **Torque**: 1.8 kg/cm
- **Cost**: ~$3-5 USD

## Display

### 0.96" OLED Display (128x64)
- **Interface**: I2C (SDA: 21, SCL: 22)
- **Color**: Blue or White text on black
- **Resolution**: 128x64 pixels
- **Cost**: ~$3-5 USD

## IR Communication

### IR Transmitter Diode
- **Pin**: GPIO 12
- **Wavelength**: 940 nm
- **Current**: 100 mA
- **Cost**: ~$0.50 USD

### IR Receiver Module
- **Pin**: GPIO 14
- **Frequency**: 38 kHz
- **Range**: ~8 meters
- **Cost**: ~$1 USD

## Power Management

### 18650 Li-Ion Battery
- **Voltage**: 3.7V nominal (4.2V max)
- **Capacity**: 2000-3500 mAh
- **Cost**: ~$3-5 USD

### TP4056 Charger Module
- **Input**: USB-C or Micro-USB
- **Max Charging Current**: 2A
- **Protection**: Over-charge, Over-discharge
- **Cost**: ~$1-2 USD

### 5V Boost Converter (MT3608)
- **Input**: 2V-24V
- **Output**: Adjustable 5V
- **Current**: Up to 2A
- **Cost**: ~$1 USD

### Battery Monitoring
- **Pin**: GPIO 34 (ADC)
- **Voltage Divider**: 2:1 ratio for 0-6.6V input range

## Storage

### MicroSD Card Module
- **Interface**: SPI (CS: 4)
- **Max Capacity**: 32GB+ (tested up to 128GB)
- **Speed**: Up to 4 MB/s
- **Cost**: ~$1-2 USD

## Total Component Cost

| Category | Cost | Quantity |
|----------|------|----------|
| ESP32 DevKit | $12 | 1 |
| Sensors | $50 | 8 |
| Actuators | $15 | 4 |
| Display | $4 | 1 |
| IR Components | $2 | 2 |
| Power Management | $10 | 3 |
| Storage | $2 | 1 |
| **Total** | **~$95-120** | |

## Where to Buy

- **AliExpress**: Cheapest option, 2-4 week shipping
- **Banggood**: Good prices, faster shipping than AliExpress
- **Amazon**: Faster shipping, higher prices
- **eBay**: Good for used components
- **Local Electronics Shops**: Higher prices but instant availability

## Wiring Tips

1. Use breadboard for prototyping
2. Color-code wires: Red=5V, Black=GND, Yellow=SDA, Green=SCL
3. Add pull-up resistors (10kΩ) to I2C lines
4. Add capacitors (100µF) near power pins
5. Keep wires short to reduce noise
6. Use heatshrink tubing to protect connections
