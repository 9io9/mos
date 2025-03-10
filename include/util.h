#ifndef __KERNEL_MOS_UTIL_H

#define __KERNEL_MOS_UTIL_H

#include "include/type.h"

// do not use malloc, only stack
void strcpy32(const u8* from, u8* to);
void memcpy32(const u8* from, u8* to, u32 bytes);
void memset32(u8* where, u8 val, u32 bytes);

#endif