/*
 * File: main.cpp
 * File Created: Tuesday, 11th January 2022 11:29 pm
 * Author: Lia Murphy (wxm219@miami.edu)
 */

#include "NimBLEDevice.h"
#include "NimBLEServer.h"

extern "C" void app_main(void) {
    
    NimBLEDevice::init("device name esp lol");

    NimBLEServer *pServer = NimBLEDevice::createServer();
    NimBLEService *pService = pServer->createService("ABCD");
    NimBLECharacteristic *pCharacteristic = pService->createCharacteristic("1234");
    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();

    pService->start();
    pCharacteristic->setValue("hello");
    pAdvertising->addServiceUUID("ABCD");
    pAdvertising->start();

}



