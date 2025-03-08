include Config.mk
include core/alloc/Alloc.mk
include core/pci/Pci.mk
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
	rm $(wildcard boot/*.aso) $(wildcard boot/*.o) $(wildcard boot/*.bin) $(wildcard boot/*.S)  $(wildcard boot/*.img) \
	$(wildcard core/*.o) $(wildcard core/pci/*.o) $(wildcard core/utils/*.o) $(wildcard *.log) $(wildcard core/alloc/*.o)

.PHONY: run clean