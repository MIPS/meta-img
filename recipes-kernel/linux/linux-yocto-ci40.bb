inherit kernel
require recipes-kernel/linux/linux-yocto.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

LINUX_VERSION ?= "4.1%"
PV = "4.1.13"

KBRANCH = "openwrt-4.1.13"
SRC_URI = "git://github.com/CreatorDev/linux.git;protocol=https;branch=${KBRANCH}"
SRC_URI	+= "file://0001-compiler-gcc-integrate-the-various-compiler-gcc-345-.patch"
SRC_URI	+= "file://0001-dts-ci40-Update-dts-from-openwrt-repository.patch"
SRCREV = "98c75976c467718171091d9fb9b96f07c269e9de"

LINUX_VERSION_EXTENSION ?= "-ci40+${SRCREV}"

COMPATIBLE_MACHINE = "ci40"
KBUILD_DEFCONFIG = "pistachio_defconfig"
KCONFIG_MODE = "--alldefconfig"

KERNEL_DEVICETREE = "pistachio/pistachio_marduk.dtb"
KERNEL_EXTRA_ARGS = "dtbs"
KMACHINE = "pistachio"
