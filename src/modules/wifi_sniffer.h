#ifndef WIFI_SNIFFER_H
#define WIFI_SNIFFER_H

#include <Arduino.h>
#include "../config.h"
#include <esp_wifi.h>
#include <esp_wifi_types.h>

struct CapturedPacket {
    uint8_t mac_src[6];
    uint8_t mac_dst[6];
    uint16_t frame_type;
    int8_t rssi;
    uint8_t channel;
    uint32_t timestamp;
};

class WiFiSniffer {
public:
    WiFiSniffer() : packet_count(0) {}
    
    void init() {
        if (!ENABLE_WIFI_SNIFFER) return;
        
        // Set WiFi to promiscuous mode
        wifi_promiscuous_filter_t filter = {
            .filter_mask = WIFI_PROMIS_FILTER_MASK_MGMT | WIFI_PROMIS_FILTER_MASK_DATA
        };
        esp_wifi_set_promiscuous(true);
        esp_wifi_set_promiscuous_filter(&filter);
        esp_wifi_set_promiscuous_rx_cb(&promisc_callback);
    }
    
    void update() {
        // Update sniffer state
    }
    
    void startScan(uint8_t channel = SNIFFER_CHANNEL) {
        if (!ENABLE_WIFI_SNIFFER) return;
        esp_wifi_set_channel(channel, WIFI_SECOND_CHAN_NONE);
    }
    
    uint16_t getPacketCount() { return packet_count; }
    
private:
    uint16_t packet_count;
    
    static void promisc_callback(void* buf, wifi_promiscuous_pkt_type_t type) {
        // Handle captured packets
    }
};

#endif // WIFI_SNIFFER_H
