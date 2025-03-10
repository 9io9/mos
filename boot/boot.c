#include "include/boot.h"
#include "include/pio.h"
#include "include/pci.h"
#include "include/util.h"
#include "include/dalloc.h"
#include "include/vga.h"

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
  VGATextEnv venv;

  if (vga_init(&venv, (BootData*) BOOT_DATA) == True) {
    vga_write((const u8*) "Boot Success\n", &venv);
  }

  while (1);
}