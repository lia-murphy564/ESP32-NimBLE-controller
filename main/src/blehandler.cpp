/*
 * File: blehandler.cpp
 * File Created: Wednesday, 12th January 2022 4:54 pm
 * Author: Lia Murphy (wxm219@miami.edu)
 */

#include "blehandler.h"

void ble_init() {

    NimBLEDevice::init("device name esp lol");

    NimBLEServer *pServer = NimBLEDevice::createServer();
    NimBLEService *pService = pServer->createService((char*)SERVICE_ID);

    NimBLECharacteristic *pCharacteristic = pService->createCharacteristic(
        (char*)DATA_CHARACTERISTIC_ID, 
        NIMBLE_PROPERTY::READ | 
        NIMBLE_PROPERTY::WRITE | 
        NIMBLE_PROPERTY::NOTIFY
        );

    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();

    pService->start();
    pCharacteristic->setValue("hello");
    pAdvertising->addServiceUUID((char*)SERVICE_ID);
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