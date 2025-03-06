boot_c := $(wildcard boot/*.c)
boot_c_obj := $(patsubst %.c,%.o,${boot_c})
boot/boot.bin: boot/boot.asm
	nasm -O0 -f bin -o $@ $<
boot/%.o: boot/%.c
	${CC} -O0 -m32 ${cflags} -c $< -o $@
boot/boot.img: ${boot_c_obj} ${pci_obj}
	${LD} ${ld_flags} -e loader_main -Ttext=0x7e00 -o $@ $^
	objcopy -O binary -j .text $@ $@
boot-dump:
	objdump -b binary -M intel -m i386 -D boot/boot.bin > boot/boot.S
	objdump -b binary -M intel -m i386 -D boot/boot.img > boot/boot.img.S
