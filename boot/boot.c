#include "include/boot.h"
#include "include/pio.h"
#include "include/pci.h"
#include "include/util.h"
#include "include/dalloc.h"

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
  BootData* bd = (BootData*) BOOT_DATA;

  u8* boot_str = dalloc(13, bd, bd->data_end - bd->data_start + 1);

  boot_str[0] = 'B';
  boot_str[1] = 'o';
  boot_str[2] = 'o';
  boot_str[3] = 't';
  boot_str[4] = ' ';
  boot_str[5] = 'S';
  boot_str[6] = 'u';
  boot_str[7] = 'c';
  boot_str[8] = 'c';
  boot_str[9] = 'e';
  boot_str[10] = 's';
  boot_str[11] = 's';

  u8* vga = ((u8*) VGA_START);

  for (u32 sid = 0; sid < 13; ++sid) {
    vga[sid << 1] = boot_str[sid];
    vga[(sid << 1) + 1] = 0x0F;
  }

  while (1);
}