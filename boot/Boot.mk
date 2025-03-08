boot_c := $(wildcard boot/*.c)
boot_asm := $(wildcard boot/*.asm)
boot_aso := $(patsubst %.asm,%.aso,${boot_asm})
boot_c_obj := $(patsubst %.c,%.o,${boot_c})
# 
boot/%.aso: boot/%.asm
	nasm -O0 -f bin -o $@ $<
boot/%.o: boot/%.c
	${CC} -O0 -m32 ${cflags} -c $< -o $@
boot/boot.img: ${boot_c_obj} ${pci_obj} ${boot_aso} ${alloc_obj}
	dd if=boot/boot.aso of=$@ conv=notrunc
	${LD} ${ld_flags} -e loader_main -T boot/boot.ld -o boot/boot2.bin $(patsubst %.aso,,$^)
	objcopy -O binary -j .text boot/boot2.bin boot/boot2.bin
	dd if=boot/boot2.bin of=$@ bs=512 seek=1 conv=notrunc
boot-dump:
	objdump -b binary -M intel -m i386 -D boot/boot.img > boot/boot.S
