QEMU
====

There are two ways of using QEMU.

## runqemu wrapper script

If you are using Yocto/Poky, runqemu is a script that comes with the installation
that allows one to start a qemu instance easily. The default search paths runqemu
comes with are for the yocto-bsp endpoints. To use the output for target machines
in meta-img, you will have to manually specify the kernel and rootfs for runqemu.
e.g.

	KERNEL=tmp/deploy/images/qemumips32r2/vmlinux ROOTFS=tmp/deploy/images/qemumips32r2/core-image-minimal-qemumips32r2.tar.bz2  runqemu qemumips qemuparams="-nographic"
	KERNEL=tmp/deploy/images/qemumips32r2el/vmlinux ROOTFS=tmp/deploy/images/qemumips32r2el/core-image-minimal-qemumips32r2el.tar.bz2  runqemu qemumipsel qemuparams="-nographic"
<TODO add more examples>

## Directly use qemu
You can also use QEMU directly e.g.

	qemu-system-mips64 -cpu 'MIPS64R2-generic' -kernel tmp/deploy/images/qemumips64r2/vmlinux -nographic -append "console=ttyS0"
<TODO add more examples>