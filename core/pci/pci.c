#include "include/pio.h"
#include "include/pci.h"

u32 pci_address(u8 bus, u8 dev, u8 func, u8 reg) {
  return (u32) ((((u32) bus) << 16) | (((u32) dev) << 11) | (((u32) func) << 8) | (reg << 2) | ((u32) 0x80000000));
}

u32 pci_ioread(u32 base_addr, u8 reg_id) {
  u32 reg_value;

  base_addr &= 0xFFFFFF00;
  base_addr |= reg_id << 2;

  outl(IOPORT(PCI, CFG_ADDR), base_addr);
  inl(IOPORT(PCI, CFG_DATA), &reg_value);

  return reg_value;
}