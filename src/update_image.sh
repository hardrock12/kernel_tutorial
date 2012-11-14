#!/bin/bash

hdiutil attach floppy.img -mountpoint mnt -nobrowse 
cp src/kernel /mnt/kernel
hdiutil detach mnt
