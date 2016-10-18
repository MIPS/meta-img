QEMU
====

There are two ways of using QEMU.

## runqemu wrapper script

If you are using Yocto/Poky, runqemu is a script that makes it very easy.

After running bitbake for a machine, you need to simply run 'runqemu path_to_folder_with_image nographic'

	~$ runqemu tmp/deploy/images/qemumips32r2el nographic
	~$ runqemu tmp/deploy/images/qemumips32r6el nographic
	~$ runqemu tmp/deploy/images/qemumips64r2el nographic
	~$ runqemu tmp/deploy/images/qemumips64r6el nographic
	etc.

## Directly use qemu
You can also use QEMU directly e.g.

	qemu-system-mips64 -cpu 'MIPS64R2-generic' -kernel tmp/deploy/images/qemumips64r2/vmlinux -nographic -append "console=ttyS0"

If you use runqemu, it tells you the complete command line options that runqemu uses. That is a handy reference.
