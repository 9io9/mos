#ifndef __KERNEL_MOS_BOOT_H

#define __KERNEL_MOS_BOOT_H

#include "include/type.h"

#define BDA_START ((u32) 0x400)
#define BOOT_START ((u32) 0x7c00)
#define BOOT_END ((u32) 0x7FFFF)
#define BOOT_STACK_TOP ((u32) 0x7F000)
#define BOOT_STACK_BOT BOOT_END
#define BOOT_STACKSIZE ((u32) 0x1000) // 4k
#define BOOT_MEMSIZE ((u32) 0x77400)
#define BOOT_DATA ((u32) 0x7db4)

#define VGA_START ((u32) 0xB8000)

#pragma pack(push, 1)
typedef struct BootData {
  u16 gdtr_limit;
  u32 gdtr_base[2];
  u8 gdt[40];
  u8 useless[16]; // dap for real mode buf useless in pe mode
  u32 data_end;
  u32 data_start;
}BootData;
#pragma pack(pop)

#endif