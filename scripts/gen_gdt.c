#include <stdint.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  int code_or_data = 0;
  int can_read = 0;
  int can_form = 0;
  int dpl = 0;
  int present = 0;
  int G = 0;
  int D = 0;
  uint8_t attr1 = 0;
  uint32_t seglim = 0;
  uint32_t baddr = 0;

  printf("GDT type (0=code,1=data):\n");
  scanf("%d", &code_or_data);
  printf("Seg limit (20bits, int):\n");
  scanf("%u", &seglim);
  printf("Base address(32bits, int):\n");
  scanf("%u", &baddr);

  uint64_t desc = 0;
  
  if (code_or_data == 0) {
    printf("Can Read (1=can,0=can't):\n");
  } else {
    printf("Can Write (1=can,0=can't):\n");
  }

  scanf("%d", &can_read);

  if (can_read) {
    attr1 |= 0x02;
  }

  if (code_or_data == 0) {
    printf("Can Form (1=can,0=can't):\n");
  } else {
    printf("Expand down/up (0=up,1=down):\n");
  }

  scanf("%d", &can_form);

  if (can_form) {
    attr1 |= 0x04;
    if (code_or_data == 1) {
      int reassign_addr = 0;
      printf("Do you need reassign base addr(1=yes,0=no):\n");
      scanf("%d", &reassign_addr);

      if (reassign_addr) {
        printf("New base addr:\n");
        scanf("%d", &baddr);
      }
    }
  }

  printf("DPL(0=kernel,1,2=super,3=user):\n");
  scanf("%d", &dpl);

  printf("Present (0=not,1=yes):\n");
  scanf("%d", &present);
  
  printf("G flag(1=4k unit limit,0=byte unit limit):\n");
  scanf("%d", &G);

  if (code_or_data == 0) {
    printf("D flag (1=32bits code,0=16bits code):\n");
  } else {
    printf("B/D flag (1=32bits address or 32bits stack,0=16bits address or 16 bits stack):\n");
  }

  scanf("%d", &D);

  if (code_or_data == 0) {
    attr1 |= 0x18;
  } else {
    attr1 |= 0x10;
  }

  attr1 |= dpl << 5;
  attr1 |= present << 7;
  desc |= 0xFFFF & seglim;
  desc |= ((uint64_t) ((0xF0000 & seglim) >> 16)) << 48;
  desc |= (uint64_t) G << 55;
  desc |= ((uint64_t) (0xFFFF & baddr)) << 16;
  desc |= ((uint64_t) ((0xFF0000 & baddr) >> 16)) << 32;
  desc |= (uint64_t) D << 54;
  desc |= ((uint64_t) ((0xFF000000 & baddr) >> 24)) << 56;
  desc |= (uint64_t) attr1 << 40;

  printf("0x%016lx\n", desc);

  return 0;
}