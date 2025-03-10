#include "include/dalloc.h"

void* dpush(u32 ds, BootData* bd) {
  ds += sizeof(u32);
  
  if (bd->data_start + ds - 1 > bd->data_end) {
    return NIL;
  }

  bd->data_end -= ds;

  ((u32*) (bd->data_end + 1))[0] = ds - sizeof(u32);

  return (void*) (bd->data_end + 1 + sizeof(u32));
}

void dpop(BootData* bd) {
  if (bd->data_end == BOOT_STACK_TOP - 1) {
    return;
  }
  
  bd->data_end += ((u32*) (bd->data_end + 1))[0] + sizeof(u32);
}