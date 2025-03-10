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
    "pushl %%esi\n\t"
    "pushl %%edi\n\t"
    "pushl %%ecx\n\t"
    "movl %0, %%esi\n\t"
    "movl %1, %%edi\n\t"
    "movl %2, %%ecx\n\t"
    "rep movsb\n\t"
    "popl %%ecx\n\t"
    "popl %%edi\n\t"
    "popl %%esi\n\t"
    :
    : "r" (from), "r" (to), "r" (bytes)
    : "memory"
  );
}