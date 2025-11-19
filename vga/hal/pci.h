#pragma once

#include <sextant/types.h>

ui32_t pciConfigReadDoubleWord(ui8_t bus, ui8_t slot, ui8_t func, ui8_t offset);
ui16_t pciConfigReadWord(ui8_t bus, ui8_t slot, ui8_t func, ui8_t offset);
ui8_t pciConfigReadByte(ui8_t bus, ui8_t slot, ui8_t func, ui8_t offset);

ui16_t getVendorID(ui8_t bus, ui8_t device, ui8_t function);
ui16_t getDeviceID(ui8_t bus, ui8_t device, ui8_t function);
ui8_t getHeaderType(ui8_t bus, ui8_t device, ui8_t function);
ui8_t getBaseClass(ui8_t bus, ui8_t device, ui8_t function);
ui8_t getSubClass(ui8_t bus, ui8_t device, ui8_t function);
ui8_t getSecondaryBus(ui8_t bus, ui8_t device, ui8_t function);

void checkDevice(ui8_t bus, ui8_t device);

void checkFunction(ui8_t bus, ui8_t device, ui8_t function);

void checkBus(ui8_t bus);
