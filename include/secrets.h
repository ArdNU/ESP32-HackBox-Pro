#ifndef SECRETS_H
#define SECRETS_H

// ============= SENSITIVE DATA - CHANGE BEFORE DEPLOYMENT =============

// WiFi Credentials
const char* WIFI_SSID_PRIMARY = "YourSSID";
const char* WIFI_PASSWORD_PRIMARY = "YourPassword";

// API Keys
const char* API_KEY = "your_api_key_here";
const char* LOCATION_API_KEY = "your_location_api_key";

// Device Tokens
const char* DEVICE_TOKEN = "your_device_token";
const char* AUTH_TOKEN = "your_auth_token";

// Known MAC Addresses (Whitelist/Blacklist)
const char* KNOWN_DEVICES[] = {
    "AA:BB:CC:DD:EE:FF",
    "11:22:33:44:55:66"
};

// Wordlist for brute force (stored in PROGMEM to save RAM)
const char* WEAK_PASSWORDS[] PROGMEM = {
    "123456",
    "password",
    "12345678",
    "qwerty",
    "abc123",
    "monkey",
    "1234567",
    "letmein",
    "trustno1",
    "dragon"
};

#endif // SECRETS_H
