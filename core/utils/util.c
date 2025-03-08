#include "include/util.h"

void strcpy32(const u8* from, u8* to) {
  u32 from_len = 0;
  
  while (from[from_len] != '\0') {
    to[from_len] = from[from_len];
    from_len += 1;
  }
  
  return;
}

void memcpy32(const u8* from, u8* to, u32 bytes) {
  asm volatile (
    "movl %0, %%esi"
    "movl %1, %%edi"
    "movl %2, %%ecx"
    "movsb"
    :
    : "r" (from), "r" (to), "r" (bytes)
    : "memory"
  );
}