pci_src := $(wildcard core/pci/*.c)
pci_obj := $(patsubst %.c,%.o,${pci_src})

core/pci/%.o: core/pci/%.c
	${CC} -m32 ${cflags} -c $< -o $@