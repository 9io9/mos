# qemu configs
qemu := qemu-system-x86_64
qemu_mem := -m 256M
qemu_cpu := -smp 2
qemu_disks := sata0.disk nvme.disk
qemu_sata := -device ahci,id=ahci -drive file=sata0.disk,format=raw,if=none,id=sata0 -device ide-hd,drive=sata0,bus=ahci.0
qemu_nvme := -drive file=nvme.disk,format=raw,if=none,id=nvme0 -device nvme,drive=nvme0,serial=1344
qemu_net := -device virtio-net-pci,netdev=net0,bus=root0 -netdev user,id=net0
qemu_usb := -usb -device usb-mouse -device usb-kbd
qemu_vga := -vga std
qemu_pcie := -device pcie-root-port,id=root0,chassis=1
qemu_boot := -boot c
qemu_gdb := -s -S
qemu_flags := -machine q35 ${qemu_mem} ${qemu_boot} ${qemu_cpu} ${qemu_pcie} ${qemu_sata} ${qemu_nvme} ${qemu_ide} ${qemu_net} ${qemu_usb} ${qemu_vga} 

# c configs
cflags_warn := -Wall -Werror
cflags_exclude := -fcf-protection=none -fno-builtin -fno-stack-protector -fomit-frame-pointer -fno-pic -fno-pie -nostdlib -fno-inline -nostartfiles -ffreestanding -D__ASSEMBLY__ -U_FORTIFY_SOURCE
cflags := -I. ${cflags_warn} ${cflags_exclude}

# ld configs
ld_flags := -m elf_i386 -nostdlib -nodefaultlibs -nostartfiles