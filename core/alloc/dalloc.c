#include "include/dalloc.h"

void* dalloc(u32 ds, BootData* bd, u32 dl) {
  if (ds > dl) {
    return (void*) 0;
  }

  bd->data_end -= ds;

  return (void*) (bd->data_end + 1);
}