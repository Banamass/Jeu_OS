#include "pci.h"

#include <hal/fonctionsES.h>
#include <drivers/EcranBochs.h>

#include <drivers/Ecran.h>
Ecran e;

/* hugely inspired from the PCI page of OS Dev WIKI
* https://wiki.osdev.org/PCI
*/

ui32_t pciConfigReadDoubleWord(ui8_t bus, ui8_t slot, ui8_t func, ui8_t offset) {
    ui32_t address;
    ui32_t lbus  = (ui32_t)bus;
    ui32_t lslot = (ui32_t)slot;
    ui32_t lfunc = (ui32_t)func;
  
    // Create configuration address as per Figure 1
    address = (ui32_t)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | (offset & 0xFC) | ((ui32_t)0x80000000));
  
    // Write out the address
    
    ecrireMotLong(address, 0xCF8);
    // Read in the data
    return lireMotLong(0xCFC);
}

ui16_t pciConfigReadWord(ui8_t bus, ui8_t slot, ui8_t func, ui8_t offset) {
    return (ui16_t)((pciConfigReadDoubleWord(bus, slot, func, offset) >> ((offset & 2) * 8)) & 0xFFFF);
}

ui8_t pciConfigReadByte(ui8_t bus, ui8_t slot, ui8_t func, ui8_t offset) {
    ui16_t tmp = pciConfigReadWord(bus, slot, func, offset);
    return (ui8_t)((tmp >> ((offset & 1) * 8)) & 0xFF);
}

ui16_t getVendorID(ui8_t bus, ui8_t device, ui8_t function) {
    return pciConfigReadWord(bus, device, function, 0x00);
}

ui16_t getDeviceID(ui8_t bus, ui8_t device, ui8_t function) {
    return pciConfigReadWord(bus, device, function,0x02);
}

ui8_t getHeaderType(ui8_t bus, ui8_t device, ui8_t function) {
    return pciConfigReadByte(bus, device, function, 0x10);
}

ui8_t getBaseClass(ui8_t bus, ui8_t device, ui8_t function) {
    return pciConfigReadByte(bus, device, function, 0x0B);
}

ui8_t getSubClass(ui8_t bus, ui8_t device, ui8_t function) {
    return pciConfigReadByte(bus, device, function, 0x0A);
}

ui8_t getSecondaryBus(ui8_t bus, ui8_t device, ui8_t function) {
    return pciConfigReadByte(bus, device, function, 0x19);
}

void dumpRegisters(ui8_t bus, ui8_t device, ui8_t function) {
    for (ui8_t offset = 0; offset < 16; offset++) {
        ui16_t bottom = pciConfigReadWord(bus, device, function, offset * 4);
        e.afficherMot("offset "); e.afficherBase(offset, 16);
        e.afficherMot(" -> "); e.afficherBase(bottom, 16); 
        e.afficherMot(", ");
        ui16_t top = pciConfigReadWord(bus, device, function, offset * 4 + 2);
        e.afficherBase(top, 16); e.afficherMot("\n");
    }
}

void checkDevice(ui8_t bus, ui8_t device) {
    ui8_t function = 0;

    ui16_t vendorID = getVendorID(bus, device, function);
    if (vendorID == 0xFFFF) return; // Device doesn't exist

    e.afficherBase(bus, 16);
    e.afficherMot(":");
    e.afficherBase(device, 16);
    e.afficherMot(" -> ");
    e.afficherBase(vendorID, 16);
    e.afficherMot(":");
    e.afficherBase(getDeviceID(bus, device, function), 16);
    e.afficherMot("\n");
    // dumpRegisters(bus, device, function);

    checkFunction(bus, device, function);
    ui8_t headerType = getHeaderType(bus, device, function);
    if( (headerType & 0x80) != 0) {
        // It's a multi-function device, so check remaining functions
        e.afficherMot("found bridge");
        for (function = 1; function < 8; function++) {
            if (getVendorID(bus, device, function) != 0xFFFF) {
                checkFunction(bus, device, function);
            }
        }
    }
}

void checkBus(ui8_t bus) {
    ui8_t device;

    e.afficherMot("checking bus: ");
    e.afficherChiffre(bus);
    e.afficherMot("\n");

    for (device = 0; device < 32; device++) {
        checkDevice(bus, device);
    }
}

void checkFunction(ui8_t bus, ui8_t device, ui8_t function) {
    ui8_t baseClass;
    ui8_t subClass;
    ui8_t secondaryBus;

    baseClass = getBaseClass(bus, device, function);
    subClass = getSubClass(bus, device, function);

    if ((baseClass == 0x6) && (subClass == 0x4)) {
        secondaryBus = getSecondaryBus(bus, device, function);
        checkBus(secondaryBus);
    }
    else {
        ui16_t deviceID = getDeviceID(bus, device, function);
        ui16_t vendorID = getVendorID(bus, device, function);
        
        // we found our Bochs card, we save the buffer address to our driver
        if (deviceID == EcranBochs::PCI_DEVICE && vendorID == EcranBochs::PCI_VENDOR) {
            ui32_t bar0 = pciConfigReadDoubleWord(bus, device, function, 0x10) & 0xFFFFFFF0;
            
            EcranBochs::VRAM = (ui8_t*)bar0;
            // save the BAR
        }
    }
}