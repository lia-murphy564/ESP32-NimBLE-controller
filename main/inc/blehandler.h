/*
 * File: blehandler.h
 * File Created: Wednesday, 12th January 2022 4:54 pm
 * Author: Lia Murphy (wxm219@miami.edu)
 */

#ifndef __BLEHANDLER_H__
#define __BLEHANDLER_H__

#include "NimBLEDevice.h"

#include <cstdint>

#define DEVICE_NAME             "ESP32 woot"
#define SERVICE_ID              0x1700
#define DATA_CHARACTERISTIC_ID  0x1A00

enum data_length_enum {
    d_byte = 1,
    d_hword = 8,
    d_word = 16
};

void ble_init();

// class ServerCallbacks: public NimBLEServerCallbacks {
//     void onConnect(NimBLEServer* pServer);
//     void onDisconnect(NimBLEServer* pServer);
// };

// class CharacteristicCallbacks: public NimBLECharacteristicCallbacks {};

#endif // __BLEHANDLER_H__