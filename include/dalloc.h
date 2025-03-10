#ifndef __KERNEL_MOS_DALLOC_H
#define __KERNEL_MOS_DALLOC_H

#include "include/boot.h"

void* dpush(u32 ds, BootData* bd);

void dpop(BootData* bd);

#endif