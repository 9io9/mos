alloc_src := $(wildcard core/alloc/*.c)
alloc_obj := $(patsubst %.c,%.o,${alloc_src})

core/alloc/%.o: core/alloc/%.c
	${CC} -m32 ${cflags} -c $< -o $@