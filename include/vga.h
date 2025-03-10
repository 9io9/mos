#ifndef __KERNEL_MOS_VGA_H

#define __KERNEL_MOS_VGA_H

#include "include/dalloc.h"

#define VGA_TEXT_START ((u32) 0xB8000)
#define VGA_TEXT_LINEMAX ((u8) 0x19)
#define VGA_TEXT_COLMAX ((u8) 0x50)

typedef struct VGATextEnv {
  u8 line;
  u8 col;
  u8* buffer; // 4K
}VGATextEnv;

bool vga_init(VGATextEnv* env, BootData* bd);

void vga_write(const u8* str, VGATextEnv* env);

#endif