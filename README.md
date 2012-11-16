kernel_tutorial
===============

A kernel dev project for a dummy like me.

I am following the "Roll your own toy UNIX-clone OS" tutorial from
James Molloy at
<http://www.jamesmolloy.co.uk/tutorial_html/index.html>. I am trying
to develop it from my MacosX box (Snow Leopard) directly, and run my
own generated kernel with Bochs, an i386 virtual machine
(<http://bochs.sourceforge.net/>); I installed Bocks from MacPorts
(<http://www.macports.org/>).

At some point I could have host my developement process in a virtual
machine running a fully-fledged Linux distro (as Ubuntu), running
itself a Bochs virtual machine to host my home-made kernel, and thus
avoid the pain to find the development tools advised for Linux users
on virtually every kernel development tutorial on the Web. But I
really wanted to prove by myself that developing a kernel on MacosX
platform was possible. I took it as "challenge" :-). Macports helped a
lot in that strugle. ;-)

Here is a list of package names from macports that I need:
* bochs
* i386-elf-binutils
* i386-elf-gcc (installed with `port install
i386-elf-gcc configure.compiler=clang` on my Snow Leopard machine. The
default compiler being **llvm-gcc-4.2** and failed for me.)
* nasm

A big tutorial resource for me was <wiki.osdev.org/>.

TODO
====

1. Test gnu-binutils's ld validity.

2. Test nasm validity.

3. Adapt update_image.sh script to mac os x (using `hdiutil mount
floppy.img -mountpoint mnt`).

4. Adapt run_bochs.sh script to mac os x.

5. Provided image being read-only. Manage to get a proper bootable image. With an MBR partition (look into diskutil or fdisk). And install Grub into this new image (look into Grub documentation and/or the osdev ressource page on <a href="http://wiki.osdev.org/GRUB"> Grub. </a>