kernel_tutorial
===============

A kernel dev project for a dummy like me.


TODO
====

1. Test gnu-binutils's ld validity.

2. Test nasm validity.

3. Adapt update_image.sh script to mac os x (using `hdiutil mount
floppy.img -mountpoint mnt`).

4. Adapt run_bochs.sh script to mac os x.

5. Provided image being read-only. Manage to get a proper bootable image. With an MBR partition (look into diskutil or fdisk). And install Grub into this new image (look into Grub documentation and/or the osdev ressource page on <a href="http://wiki.osdev.org/GRUB"> Grub. </a>