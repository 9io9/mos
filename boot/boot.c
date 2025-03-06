#include "include/boot.h"
#include "include/pio.h"
#include "include/pci.h"

#pragma pack(push, 4)
typedef struct  ELFHeader32 {
  u8 e_ident[16];
  u16 e_type;
  u16 e_machine;
  u32 e_version;
  u32 e_entry;
  u32 e_phoff;
  u32 e_shoff;
  u32 e_flags;
  u16 e_ehsize;
  u16 e_phentsize;
  u16 e_phnum;
  u16 e_shentsize;
  u16 e_shnum;
  u16 e_shstrndx;
}ELFHeader32;
#pragma pack(pop)

void loader_main(void) {
  u8* vga_start = (u8*) 0xB800;

  vga_start[0] = 'S';
  vga_start[1] = 0x0F;

  while (1);
}