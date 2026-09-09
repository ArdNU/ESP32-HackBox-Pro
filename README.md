# ESP32 HackBox Pro 🔥

Universal multi-tool for penetration testing, IoT hacking, and network analysis powered by ESP32.

## 🎯 Features

### Network Attacks
- ✅ WiFi Sniffer (packet capture in promiscuous mode)
- ✅ Deauthentication Attack
- ✅ ARP Spoofing (Man-in-the-Middle)
- ✅ DNS Spoofing
- ✅ Port Scanning
- ✅ Evil Twin AP
- ✅ SSL Stripping

### Device Control
- 📱 IR Remote Control (AC, TV, any IR device)
- 🌐 Web Dashboard
- 📡 Bluetooth Control (BLE + Classic)
- 🔌 Power Relay Control
- 🎮 Servo Motor Control

### Sensors
- 🌡️ Temperature & Humidity (DHT22)
- 📊 Pressure & Altitude (BMP280/BME680)
- 🎯 Motion Detection (MPU6050)
- 🗺️ GPS Tracking (NEO-6M)
- 📸 Light Sensor (BH1750)
- 🔴 Radiation Detection
- 🎤 Audio Recording (Microphone)
- 📡 NFC/RFID Scanner (RC522)

### Output & Feedback
- 🎨 OLED Display (128x64)
- 🎵 Buzzer/Audio
- 💡 RGB LED Indicators
- 📊 Real-time Analytics

### Data Storage
- 💾 EEPROM Logging
- 📦 SD Card Support
- 📈 Event Tracking
- 🔍 Packet Analysis

## 🛠️ Hardware Requirements

### Main Board
- **ESP32 DevKit** (or ESP32-S3)
- USB-C for power and programming

### Required Components
```
├── Sensors
│   ├── DHT22 (Temperature/Humidity)
│   ├── BMP280/BME680 (Pressure)
│   ├── MPU6050 (IMU)
│   ├── NEO-6M (GPS)
│   ├── RC522 (NFC/RFID)
│   └── Light Sensor
├── Actuators
│   ├── WS2812B RGB LED
│   ├── Active Buzzer (5V)
│   ├── Relay Module
│   └── SG90 Servo
├── Display
│   └── 0.96" OLED (I2C)
├── Power
│   ├── 18650 Battery
│   ├── TP4056 Charger
│   └── Voltage Regulator
├── Communication
│   ├── MicroSD Card Module
│   ├── IR Transmitter
│   └── IR Receiver
```

## 📦 Installation

### 1. Clone Repository
```bash
git clone https://github.com/ArdNU/ESP32-HackBox-Pro.git
cd ESP32-HackBox-Pro
```

### 2. Install PlatformIO
```bash
pip install platformio
```

### 3. Configure
Edit `include/config.h` with your pin assignments and settings.

### 4. Build & Upload
```bash
platformio run --target upload
```

### 5. Monitor
```bash
platformio device monitor
```

## 🚀 Usage

### Web Interface
Access the dashboard at: `http://192.168.4.1` (when in AP mode)

### Serial Commands
```
# Start WiFi Sniffer
SNIFFER START

# Start Deauth Attack
DEAUTH START <channel>

# Control IR
IR SEND <device> <action>

# Read Sensors
SENSORS READ

# Get Statistics
STATS SHOW
```

### Bluetooth Control
Connect via BLE with device name: `ESP32-HackBox`

## ⚙️ Configuration

Edit `include/config.h` to:
- Assign GPIO pins
- Enable/disable modules
- Set WiFi credentials
- Configure attack parameters
- Adjust sensor thresholds

## 📚 Documentation

- [Hardware Setup](docs/COMPONENTS.md)
- [Pin Assignments](docs/PINOUTS.md)
- [API Reference](docs/API.md)
- [Troubleshooting](docs/TROUBLESHOOTING.md)

## 🔐 Security Notice

⚠️ **This tool is for:**
- Personal learning and education
- Authorized penetration testing
- Network research on owned networks

❌ **NOT for:**
- Unauthorized network access
- Hacking others' devices
- Illegal activities

The author is not responsible for misuse of this tool.

## 📝 License

MIT License - see LICENSE file for details

## 🤝 Contributing

Contributions are welcome! Please:
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## 📞 Support

Issues and feature requests: https://github.com/ArdNU/ESP32-HackBox-Pro/issues

---

**Made with ❤️ by hackers, for hackers** 🔓
