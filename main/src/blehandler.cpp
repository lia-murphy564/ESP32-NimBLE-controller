/*
 * File: blehandler.cpp
 * File Created: Wednesday, 12th January 2022 4:54 pm
 * Author: Lia Murphy (wxm219@miami.edu)
 */

#include "blehandler.h"

void ble_init() {

    NimBLEDevice::init("device name esp lol");

    NimBLEServer *pServer = NimBLEDevice::createServer();
    NimBLEService *pService = pServer->createService("1234");

    NimBLECharacteristic *pCharacteristic = pService->createCharacteristic("ABCF");

    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();

    pService->start();
    pCharacteristic->setValue("hello");
    pAdvertising->addServiceUUID("1234");
    pAdvertising->start();
}

// ServerCallbacks::onConnect(NimBLEServer* pServer) {
//     printf("Device connected");

// }

// ServerCallbacks::onDisconnect(NimBLEServer* pServer) {
//     printf("Device disconnected");
// }

// CharacteristicCallbacks::onWrite(NimBLECharacteristic* pCharacteristic) {
    
// }