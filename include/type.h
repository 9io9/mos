#ifndef __KERNEL_MOS_TYPE_H

#define __KERNEL_MOS_TYPE_H

typedef int i32;
typedef unsigned int u32;
typedef char i8;
typedef unsigned char u8;
typedef short i16;
typedef unsigned short u16;

#if __WORDSIZE == 64
typedef long long i64;
typedef unsigned long long u64;
#endif

#endif