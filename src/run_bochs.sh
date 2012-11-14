#!/bin/bash

# run_bochs.sh
# mounts the correct loopback device, runs bochs, then unmounts.

hdiutil attach floppy.img -mountpoint mnt -nobrowse
bochs -f bochsrc.txt
hdiutil detach mnt
