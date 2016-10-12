Booting Instructions
====================

## Creator Ci40

The documentation for Ci40 is available on docs.creatordev.io.

Some additional notes below:

### U-Boot

 * Be very very careful if you want to flash u-boot.

Recovering u-boot from a bricked Ci40 requires external hardware.

Check the Creator Ci40 docs for more information.

https://docs.creatordev.io/ci40/guides/openwrt-platform/#building-u-boot

### Kernel

The easiest way to test the kernel is to set up a tftp server and load the kernel file via tftp.

Details are provided in the Ci40 docs here:

https://docs.creatordev.io/ci40/guides/openwrt-platform/#tftp-boot

## MIPSfpga (xilfpga)

The MIPSfpga package you have will already have instructions on how to load the Linux Kernel.

Please follow those same instructions but using the files generated in tmp/deploy/images/xilfpga/*

## QEMU


Please see the [Using QEMU](README.qemu.md) file.
