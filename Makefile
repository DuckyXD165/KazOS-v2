GCC = i586-elf-gcc
LD = i586-elf-ld

SRC = $(wildcard src/kernel/*.c)
SRC += $(wildcard src/kernel/**/*.c)
OBJ = $(patsubst src/kernel/%.c, dist/%.o, $(SRC))

all: preclean dist/floppy.img release start

preclean:
	rm -rf dist/
	mkdir dist/

release:
	rm -f dist/boot0.bin
	rm -f dist/boot1.o
	rm -f dist/kernel.bin

start: dist/floppy.img
	#qemu-system-i386 -m 128M -drive format=raw,file=dist/floppy.img
	VBoxManage startvm Test

dist/boot1.o: src/boot/boot1.asm
	nasm -f elf -o $@ $<

dist/boot0.bin: src/boot/boot0.asm
	nasm -f bin -o $@ $<

dist/%.o: src/kernel/%.c
	$(GCC) -nostdlib -nostdinc -ffreestanding -o $@ -c $<

dist/kernel.bin: dist/boot1.o $(OBJ)
	$(LD) -Ttext 0x1000 -o $@ $^ --oformat binary

dist/kernel.img: dist/boot0.bin dist/kernel.bin
	cat $^ > $@

dist/floppy.img: dist/kernel.img
	dd if=/dev/zero of=$@ bs=512 count=2880
	dd if=$< of=$@ conv=notrunc
