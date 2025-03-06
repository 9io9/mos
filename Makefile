include Config.mk
include boot/Boot.mk
include core/pci/Pci.mk

boot_imgs := boot/boot.img boot/boot.bin

run-gdb: ${qemu_disks} ${boot_imgs}
	dd if=boot/boot.bin of=sata0.disk conv=notrunc
	dd if=boot/boot.img of=sata0.disk seek=1 bs=512 conv=notrunc
	${qemu} ${qemu_gdb} ${qemu_flags}
run: ${qemu_disks} ${boot_imgs}
	dd if=boot/boot.bin of=sata0.disk conv=notrunc
	dd if=boot/boot.img of=sata0.disk seek=1 bs=512 conv=notrunc
	${qemu} ${qemu_flags}

%.disk:
	dd if=/dev/zero of=$@ bs=256M count=1
clean-disk:
	rm *.disk
clean:
	rm -r boot/*.aso boot/*.o boot/*.bin boot/*.S boot/*.img

.PHONY: run clean