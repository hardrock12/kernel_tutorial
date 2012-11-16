# Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler 
# rule, as we use nasm instead of GNU as.

SOURCES=boot.o main.o common.o monitor.o

# WARNING: this exe results in the following error (use
# i386-elf-gcc-4.3.2 instead)
# "gcc: error trying to exec 'cc1': execvp: No such file or directory"
# CC=/opt/local/i386-elf/bin/gcc

CC=/opt/local/bin/i386-elf-gcc-4.3.2
CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: floppy.img

clean:
	-rm *.o kernel pad floppy.img

kernel: $(SOURCES)
	/opt/local/i386-elf/bin/ld $(LDFLAGS) -o kernel $(SOURCES)

pad:
	dd if=/dev/zero of=pad bs=1 count=750

floppy.img: stage1 stage2 pad kernel
	cat stage1 stage2 pad kernel > floppy.img

.s.o:
	nasm $(ASFLAGS) $<
