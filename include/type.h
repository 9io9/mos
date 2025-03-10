#ifndef __KERNEL_MOS_TYPE_H

#define __KERNEL_MOS_TYPE_H

typedef enum bool {
  True = (int) 1,
  False = (int) 0
}bool;

typedef int i32;
typedef unsigned int u32;
typedef char i8;
typedef unsigned char u8;
typedef short i16;
typedef unsigned short u16;

#if MODE == 64
typedef long long i64;
typedef unsigned long long u64;

#define MAX_U64 ((u64) 0xFFFFFFFFFFFFFFFF)
#define MAX_I64 ((i64) 0x7FFFFFFFFFFFFFFF)
#define MIN_U64 ((u64) 0x0000000000000000)
#define MIN_I64 ((i64) 0x8000000000000000)

#define KB64(num) (((((u64) (num)) & ((u64) 0x003FFFFFFFFFFFFF)) + 1) << 10) // only 54 bits valid, (2^22 - 1) + 1
#define MB64(num) (((((u64) (num)) & ((u64) 0x00000FFFFFFFFFFF)) + 1) << 20) // only 44 bits valid, (2^12 - 1) + 1
#define GB64(num) (((((u64) (num)) & ((u64) 0x00000003FFFFFFFF)) + 1) << 30) // only 34 bits valid, (2^2 - 1) + 1

#endif

#define MAX_U32 ((u32) 0xFFFFFFFF)
#define MAX_I32 ((i32) 0x7FFFFFFF)
#define MIN_I32 ((i32) 0x80000000)
#define MIN_U32 ((u32) 0x00000000)
#define MAX_U16 ((u16) 0xFFFF)
#define MAX_I16 ((i16) 0x7FFF)
#define MIN_U16 ((u16) 0x0000)
#define MIN_I16 ((i16) 0x8000)
#define MAX_U8 ((u8) 0xFF)
#define MAX_I8 ((i8) 0x7F)
#define MIN_U8 ((u8) 0x00)
#define MIN_I8 ((i8) 0x80)

#define KB32(num) (((((u32) (num)) & ((u32) 0x003FFFFF)) + 1) << 10) // only 22 bits valid, (2^22 - 1) + 1
#define MB32(num) (((((u32) (num)) & ((u32) 0x00000FFF)) + 1) << 20) // only 12 bits valid, (2^12 - 1) + 1
#define GB32(num) (((((u32) (num)) & ((u32) 0x00000003)) + 1) << 30) // only 2 bits valid, (2^2 - 1) + 1

#define NIL ((void*) 0)

#endif