include Config.mk
include core/alloc/Alloc.mk
include core/pci/Pci.mk
include core/vga/Vga.mk
include core/utils/Util.mk
include boot/Boot.mk

boot_img := boot/boot.img

run-gdb: ${qemu_disks} ${boot_img}
	dd if=${boot_img} of=ide.disk conv=notrunc
	${qemu} ${qemu_gdb} ${qemu_flags}
run: ${qemu_disks} ${boot_img}
	dd if=${boot_img} of=ide.disk conv=notrunc
	${qemu} ${qemu_flags}

%.disk:
	dd if=/dev/zero of=$@ bs=256M count=1
clean-disk:
	rm *.disk
clean:
	rm -f ${boot_aso} ${boot_c_obj} $(wildcard boot/*.bin) $(wildcard boot/*.S)  $(wildcard boot/*.img) \
	$(wildcard core/*.o) $(wildcard *.log) ${pci_obj} ${vga_obj} ${util_obj} ${alloc_obj}

.PHONY: run clean