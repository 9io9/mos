#ifndef __KERNEL_MOS_PIO_H

#define __KERNEL_MOS_PIO_H

#include "include/type.h"

#define IOPORT(dev, name) dev ## _ ## name ## _PORT

static inline void inb(const u16 port, u8* ib) {
  asm(
    "inb %1\n\t"
    "movb %%al, %0"
    : "=m" (*ib)
    : "Nd" (port)
    : "memory"
  );
}

static inline void inl(const u16 port, u32* il) {
  asm (
    "inl %1\n\t"
    "movl %%eax, %0"
    : "=m" (*il)
    : "Nd" (port)
    : "memory"
  );
}

static inline void outb(const u16 port, u8 ob) {
  asm (
    "outb %0, %1"
    :
    : "a" (ob), "Nd" (port)
  );
}

static inline void outl(const u16 port, u32 ol) {
  asm (
    "outl %0, %1"
    :
    : "a" (ol), "Nd" (port)
  );
}

#endif