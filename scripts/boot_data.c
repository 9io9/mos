#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: mlayout <boot_file> <img_file>\n");
    return -1;
  }

  FILE* boot_file = fopen(argv[1], "rb");

  if (boot_file == 0) {
    printf("Can not open file %s\n", argv[1]);
  }

  fseek(boot_file, 0, SEEK_END);

  off_t boot_len = ftello(boot_file);

  FILE* img_file = fopen(argv[2], "rb+");

  if (img_file == 0) {
    printf("Can not open file %s\n", argv[2]);
  }

  fseek(img_file, 511 - 5, SEEK_SET);

  int boot_int_len = 0x7e00 + boot_len;

  fwrite(&boot_int_len, sizeof(int), 1, img_file);

  return 0;
}