#!/bin/bash

# run_bochs.sh
# mounts the correct loopback device, runs bochs, then unmounts.

# Since the "floppy.img" file is a custom one (see the Makefile which
#create it as the concatenation of stage1, stage2, pad and kernel
#files), we don't mount it. actually we can't. hditutil does not
#recognize the format, complains about it and fails. As a result,
#hdituils lines are commented here. hdiutil attach floppy.img
#-mountpoint mnt -nobrowse -readwrite
bochs -f bochsrc.txt
#hdiutil detach mnt
