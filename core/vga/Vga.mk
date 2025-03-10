vga_src := $(wildcard core/vga/*.c)
vga_obj := $(patsubst %.c,%.o,${vga_src})

core/vga/%.o: core/vga/%.c
	${CC} -m32 ${cflags} -c $< -o $@