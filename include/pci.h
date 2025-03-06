#ifndef __KERNEL_MOS_PCI_H

#define __KERNEL_MOS_PCI_H

#include "include/type.h"

#define PCI_CFG_ADDR_PORT ((u16) 0xCF8)
#define PCI_CFG_DATA_PORT ((u16) 0xCFC)

u32 pci_address(u8 bus, u8 dev, u8 func, u8 reg);
u32 pci_ioread(u32 base_addr, u8 reg);

#endif