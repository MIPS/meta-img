require recipes-bsp/u-boot/u-boot.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/files_ci40:"

DEPENDS =+ "dtc-native"

UBRANCH ?= "master-pistachio"
SRC_URI = "git://github.com/CreatorDev/u-boot.git;protocol=https;branch=${UBRANCH}"
SRC_URI += "file://001-MIPS_extern_to_static.patch"

S = "${WORKDIR}/git"
# PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "ci40"
UBOOT_MACHINE = "pistachio_marduk_defconfig"
SRCREV_pn-u-boot = "ae138751b3234885d4cc8ecb0eea9f1811ff48c8"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://README;beginline=1;endline=6;md5=157ab8408beab40cd8ce1dc69f702a6c"

#UBOOT_IMAGE = "u-boot-pistachio-nor.img"
UBOOT_BINARY = "u-boot-pistachio-nor.img"
UBOOT_SUFFIX = "img"
