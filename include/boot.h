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

#endif