kernel_tutorial
===============

A kernel dev project for a dummy like me.

I am following the "Roll your own toy UNIX-clone OS" tutorial from
James Molloy at
<http://www.jamesmolloy.co.uk/tutorial_html/index.html>. I am trying
to develop it from my MacosX box (Snow Leopard) directly, and run my
own generated kernel with Bochs, an i386 virtual machine
(<http://bochs.sourceforge.net/>); I installed Bochs from MacPorts
(<http://www.macports.org/>).

At some point I could have host my developement process in a virtual
machine running a fully-fledged Linux distro (as Ubuntu), running
itself a Bochs virtual machine to host my home-made kernel, and thus
avoid the pain to find the development tools advised for Linux users
on virtually every kernel development tutorial on the Web. But I
really wanted to prove by myself that developing a kernel on MacosX
platform was possible. I took it as "challenge" :-). Macports helped a
lot in that strugle. ;-)

Here is a list of package names from macports that I needed:
* bochs
* i386-elf-binutils
* i386-elf-gcc (installed with `port install
i386-elf-gcc configure.compiler=clang` on my Snow Leopard machine. The
default compiler being **llvm-gcc-4.2** and failed for me.)
* nasm

A big tutorial resource for me was <http://wiki.osdev.org>.

COMPILING
=========

1. Clone the repository from Github.

2. Install Macports, then the listed dependencies in the previous
section.

3. From the src/ directory type the usual `make` command.

RUNNING
=======

Still from the src/ folder:

1. Type in `ls -l kernel` to get its bytes size.

2. Invoke bochs with the dedicated script `./run_bochs.sh`.

3. Once the Bochs GUI is launched with the black screen, a GRUB
command prompt finish to appear. Type in the following command :
`grub> kernel 200+N`. N being the size of your kernel in blocks (that
is the size displayed previously divided by 512, since a block
contains 512 bytes). Type enter. Grub must reply with a line like
`[Multiboot-elf, ... shtab=...entry=...]`

4. Still from the Grub prompt, type in `boot` which launch the kernel.
Let's `hack`! ;-)



TODO
====

1. Test gnu-binutils's ld validity. => ok

2. Test nasm validity. => ok

3. Adapt update_image.sh script to mac os x (using `hdiutil mount
floppy.img -mountpoint mnt`). => remove that useless script with a
Makefile rule.

4. Adapt run_bochs.sh script to mac os x. => ok. Remove the "mounting"
part since Bochs is able to read a file instead of a block device
(from the /dev/ directory). I changed the Bochs configuration file to
do so.

5. Provided image being read-only. Manage to get a proper bootable
image. With an MBR partition (look into diskutil or fdisk). And
install Grub into this new image (look into Grub documentation and/or
the osdev ressource page on <a href="http://wiki.osdev.org/GRUB">
Grub. </a> => ok, see the previous TODO item in the list (concerning
the run_bochs.sh script).

6. Test all writen screen related function in the main function.

7. Make an interactive screen to echo what the user types.

8. See how to automate the grub initialisation and avoid to enter the
kernel blocks length by hand..

9. Stop that boring todo list, and use the issue list from Github.