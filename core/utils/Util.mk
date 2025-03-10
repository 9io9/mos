util_src := $(wildcard core/utils/*.c)
util_obj := $(patsubst %.c,%.o,${util_src})

core/utils/%.o: core/utils/%.c
	${CC} -m32 ${cflags} -c $< -o $@