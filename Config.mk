# qemu configs
qemu := qemu-system-x86_64
qemu_mem := -m 256M
qemu_cpu := -smp 4
qemu_disks := sata0.disk ide.disk
qemu_ide := -device piix4-ide,id=ide -drive file=ide.disk,format=raw,if=none,id=ide0 -device ide-hd,drive=ide0,bus=ide.0
qemu_sata := -device ich9-ahci,id=ahci -drive file=sata0.disk,format=raw,if=none,id=sata0 -device ide-hd,drive=sata0,bus=ahci.0
qemu_net := -device virtio-net-pci,netdev=net0 -netdev user,id=net0
qemu_usb := -usb -device usb-mouse -device usb-kbd
qemu_vga := -vga std
qemu_boot := -boot c
qemu_gdb := -s -S
# -machine q35 ${qemu_ide} ${qemu_sata} ${qemu_net} ${qemu_usb} 
qemu_flags := -monitor stdio  ${qemu_mem} ${qemu_boot} ${qemu_cpu} -hda ide.disk ${qemu_vga} 

# c configs
cflags_warn := -Wall -Werror
cflags_exclude := -fcf-protection=none -fno-builtin -fno-stack-protector -fomit-frame-pointer -fno-pic -fno-pie -nostdlib -fno-inline -nostartfiles -ffreestanding -D__ASSEMBLY__ -U_FORTIFY_SOURCE
cflags := -I. ${cflags_warn} ${cflags_exclude}

# ld configs
ld_flags := -m elf_i386 -nostdlib -nodefaultlibs -nostartfiles