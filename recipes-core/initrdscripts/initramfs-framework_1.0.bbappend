# Presently, we do not need to find an alternate rootfs since our 
# kernel and file system are combined.  In the future if we add
# SD card support to the MIPSfpga core, we can revisit using udev
# to bootstrap into an external filesystem if necessary.  For now,
# this append adds a 'norootfs' script

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "\
	file://userootfs \
"

do_install_append() {
    install -d ${D}/init.d
    install -m 0755 ${WORKDIR}/userootfs ${D}/init.d/89-userootfs
}

PACKAGES += "\
	initramfs-module-use-rootfs \
"
SUMMARY_initramfs-module-use-rootfs = "initramfs for skipping the search for rootfs"
RDEPENDS_initramfs-module-use-rootfs = "${PN}-base"
FILES_initramfs-module-use-rootfs = "/init.d/89-userootfs"