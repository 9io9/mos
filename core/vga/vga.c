#include "include/dalloc.h"
#include "include/util.h"
#include "include/vga.h"

#define VGA_ID(line, col, shift) (((line) * VGA_TEXT_COLMAX + (col)) << shift)

bool vga_init(VGATextEnv* env, BootData* bd) {
  env->line = 0;
  env->col = 0;
  env->buffer = (u8*) dpush(KB32(4), bd);

  if (env->buffer == NIL) {
    return False;
  }

  return True;
}

void vga_write(const u8* str, VGATextEnv* env) {
  u32 sid = 0;

  while (str[sid] != '\0') {
    if (env->col == VGA_TEXT_COLMAX) { // passive newline 
      if (env->line == VGA_TEXT_LINEMAX - 1) {
        memcpy32(env->buffer, (u8*) VGA_TEXT_START, (VGA_TEXT_LINEMAX * VGA_TEXT_COLMAX) << 1);
        memcpy32(&env->buffer[VGA_TEXT_COLMAX << 1], env->buffer, (env->line * VGA_TEXT_COLMAX) << 1);
      } else {
        env->line += 1;
      }

      env->col = 0;
    } else if (str[sid] == '\n') {
      if (env->line == VGA_TEXT_LINEMAX - 1) {
        memcpy32(env->buffer, (u8*) VGA_TEXT_START, VGA_ID(VGA_TEXT_LINEMAX, 0, 1));
        memcpy32(&env->buffer[VGA_ID(1, 0, 1)], env->buffer, VGA_ID(VGA_TEXT_LINEMAX - 1, 0, 1));
      } else {
        memcpy32(&env->buffer[VGA_ID(env->line, 0, 1)], (u8*) (VGA_TEXT_START + VGA_ID(env->line, 0, 1)), env->col << 1);
        env->line += 1;
      }

      sid += 1;
      env->col = 0;
    } else {
      env->buffer[VGA_ID(env->line, env->col, 1)] = str[sid];
      env->buffer[VGA_ID(env->line, env->col, 1) + 1] = 0x0F;

      env->col += 1;
      sid += 1;
    }
  }
}