
include recipes-core/images/core-image-minimal.bb
 
IMAGE_FSTYPES = "${INITRAMFS_FSTYPES}"
PACKAGE_INSTALL = "${IMAGE_INSTALL}"

# initramfs/initrd support for dynamic /dev
PACKAGE_INSTALL += "\
	initramfs-module-udev \
	initramfs-module-debug \
	initramfs-module-use-rootfs \
	"
BAD_RECOMMENDATIONS += "initramfs-module-rootfs"

CORE_IMAGE_EXTRA_INSTALL += "\
	simple-gpio \
"
