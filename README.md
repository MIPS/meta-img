meta-img
========

This is a BSP layer for MIPS based hardware platforms and QEMU targets usable with OpenEmbedded/Yocto

---

## Supported Machines

### qemu32/64/r2/r6/el/nf

Multiple configurations of QEMU machines in 32/64 bit, r2/r6, little/big endian, with/without fpu.

### Creator Ci40

For more information about Ci40, check http://creatordev.io.

### MIPSfpga (xilfpga)

For more information about MIPSfpga, check the following

https://www.kernel.org/doc/Documentation/devicetree/bindings/mips/img/xilfpga.txt

https://community.imgtec.com/university/resources/

---

### Additional documentation

[Building Machines](README.building.md)	Notes on how to build various machines

[Booting Machines](README.booting.md)	Notes on how to boot the various machines such as Ci40, xilfpga

[Using QEMU](README.qemu.md)		Notes on how to use qemu with the various configurations

---

## Developer info

Repository: https://www.github.com/MIPS/meta-img

Maintainer: Zubair Lutfullah Kakakhel

Pull requests: Please submit via Github PR

Issues/Bugs: Please use Github Issues

---

## Dependencies

This layer depends on bitbake and OE Core:

	git://git.openembedded.org/bitbake
	git://git.openembedded.org/openembedded-core
