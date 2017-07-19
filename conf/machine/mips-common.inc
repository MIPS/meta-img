# Include file for parameters common to many MIPS platforms

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_ALT_IMAGETYPE = "vmlinux.bin"

SERIAL_CONSOLES = "115200;ttyS0 115200;ttyS1"

# This disables gobject-introspection which needs fixing for some
# targets. If you need to use that package, remove this line.
MACHINE_FEATURES_BACKFILL_CONSIDERED = "qemu-usermode"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-yocto"

# Use GCC version 6
GCCVERSION = "6.%"

# Use qemu v2.9
PREFERRED_PROVIDER_qemu = "qemu_2.9.0"
