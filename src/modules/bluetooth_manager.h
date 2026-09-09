#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <Arduino.h>
#include "../config.h"

class BluetoothManager {
public:
    BluetoothManager() {}
    
    void initBLE() {
        if (!ENABLE_BLE) return;
        // Initialize BLE server
    }
    
    void initClassic() {
        if (!ENABLE_CLASSIC_BT) return;
        // Initialize Classic Bluetooth
    }
    
    void update() {
        // Update Bluetooth state
    }
    
private:
};

#endif // BLUETOOTH_MANAGER_H
