FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PR := "${PR}.1"

SRC_URI += "file://modules.cfg \
	    file://tracepoints.cfg \
	   "

SRC_URI_append_xilfpga += "\
	file://xilfpga-cmdline.cfg \
	file://xilfpga-periph.cfg \
	file://xilfpga-rtc.cfg \
	"

# replace these SRCREVs with the real commit ids once you've had
# the appropriate changes committed to the upstream linux-yocto repo
#SRCREV_machine_pn-linux-yocto ?= "${AUTOREV}"
#SRCREV_meta_pn-linux-yocto ?= "${AUTOREV}"
#LINUX_VERSION = "4.8"

# Configuration for Xilfpga platform

KBUILD_DEFCONFIG_xilfpga = "xilfpga_defconfig"
COMPATIBLE_MACHINE_xilfpga = "xilfpga"

# We use kernel defconfigs where everything unmarked defaults to Y but 
# Yocto defaults to allnoconfig. This parameters makes them usable in yocto
KCONFIG_MODE = "--alldefconfig"

# Configurations for various qemu machines
# Mostly rely on malta_defconfig with various appends
# But should hopefully move to generic_defconfig 4.10+

# mips32r2
COMPATIBLE_MACHINE_qemumips32r2		= "qemumips32r2"
COMPATIBLE_MACHINE_qemumips32r2-nf	= "qemumips32r2-nf"
KBUILD_DEFCONFIG_qemumips32r2		= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips32r2-nf	= "malta_defconfig"
SRC_URI_append_qemumips32r2		+= "file://mips32r2.cfg"
SRC_URI_append_qemumips32r2-nf		+= "file://mips32r2.cfg"

# mips32r2el
COMPATIBLE_MACHINE_qemumips32r2el	= "qemumips32r2el"
COMPATIBLE_MACHINE_qemumips32r2el-nf	= "qemumips32r2el-nf"
KBUILD_DEFCONFIG_qemumips32r2el		= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips32r2el-nf	= "malta_defconfig"
SRC_URI_append_qemumips32r2el		+= "file://mips32r2el.cfg"
SRC_URI_append_qemumips32r2el-nf	+= "file://mips32r2el.cfg"


# mips64r2
COMPATIBLE_MACHINE_qemumips64r2		= "qemumips64r2"
COMPATIBLE_MACHINE_qemumips64r2-n32	= "qemumips64r2-n32"
COMPATIBLE_MACHINE_qemumips64r2-o32	= "qemumips64r2-o32"
COMPATIBLE_MACHINE_qemumips64r2-nf	= "qemumips64r2-nf"
COMPATIBLE_MACHINE_qemumips64r2-nf-n32	= "qemumips64r2-nf-n32"
COMPATIBLE_MACHINE_qemumips64r2-nf-o32	= "qemumips64r2-nf-o32"

KBUILD_DEFCONFIG_qemumips64r2		= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2-n32	= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2-o32	= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2-nf	= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2-nf-n32	= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2-nf-o32	= "malta_defconfig"

SRC_URI_append_qemumips64r2		+= "file://mips64r2.cfg"
SRC_URI_append_qemumips64r2-n32		+= "file://mips64r2.cfg"
SRC_URI_append_qemumips64r2-o32		+= "file://mips64r2.cfg"
SRC_URI_append_qemumips64r2-nf		+= "file://mips64r2.cfg"
SRC_URI_append_qemumips64r2-nf-n32	+= "file://mips64r2.cfg"
SRC_URI_append_qemumips64r2-nf-o32	+= "file://mips64r2.cfg"


# mips64r2el
COMPATIBLE_MACHINE_qemumips64r2el		= "qemumips64r2el"
COMPATIBLE_MACHINE_qemumips64r2el-n32		= "qemumips64r2el-n32"
COMPATIBLE_MACHINE_qemumips64r2el-o32		= "qemumips64r2el-o32"
COMPATIBLE_MACHINE_qemumips64r2el-nf		= "qemumips64r2el-nf"
COMPATIBLE_MACHINE_qemumips64r2el-nf-n32	= "qemumips64r2el-nf-n32"
COMPATIBLE_MACHINE_qemumips64r2el-nf-o32	= "qemumips64r2el-nf-o32"

KBUILD_DEFCONFIG_qemumips64r2el		= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2el-n32	= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2el-o32	= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2el-nf	= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2el-nf-n32	= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r2el-nf-o32	= "malta_defconfig"

SRC_URI_append_qemumips64r2el		+= "file://mips64r2el.cfg"
SRC_URI_append_qemumips64r2el-n32	+= "file://mips64r2el.cfg"
SRC_URI_append_qemumips64r2el-o32	+= "file://mips64r2el.cfg"
SRC_URI_append_qemumips64r2el-nf	+= "file://mips64r2el.cfg"
SRC_URI_append_qemumips64r2el-nf-n32	+= "file://mips64r2el.cfg"
SRC_URI_append_qemumips64r2el-nf-o32	+= "file://mips64r2el.cfg"

# mips32r6
COMPATIBLE_MACHINE_qemumips32r6		= "qemumips32r6"
COMPATIBLE_MACHINE_qemumips32r6-nf	= "qemumips32r6-nf"
KBUILD_DEFCONFIG_qemumips32r6		= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips32r6-nf	= "malta_defconfig"
SRC_URI_append_qemumips32r6		+= "file://mips32r6.cfg"
SRC_URI_append_qemumips32r6-nf		+= "file://mips32r6.cfg"

# mips32r6el
COMPATIBLE_MACHINE_qemumips32r6el	= "qemumips32r6el"
COMPATIBLE_MACHINE_qemumips32r6el-nf	= "qemumips32r6el-nf"
KBUILD_DEFCONFIG_qemumips32r6el		= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips32r6el-nf	= "malta_defconfig"
SRC_URI_append_qemumips32r6el		+= "file://mips32r6el.cfg"
SRC_URI_append_qemumips32r6el-nf	+= "file://mips32r6el.cfg"

# mips32r6
COMPATIBLE_MACHINE_qemumips64r6		= "qemumips64r6"
COMPATIBLE_MACHINE_qemumips64r6-nf	= "qemumips64r6-nf"
KBUILD_DEFCONFIG_qemumips64r6		= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r6-nf	= "malta_defconfig"
SRC_URI_append_qemumips64r6		+= "file://mips64r6.cfg"
SRC_URI_append_qemumips64r6-nf		+= "file://mips64r6.cfg"

# mips64r6el
COMPATIBLE_MACHINE_qemumips64r6el	= "qemumips64r6el"
COMPATIBLE_MACHINE_qemumips64r6el-nf	= "qemumips64r6el-nf"
KBUILD_DEFCONFIG_qemumips64r6el		= "malta_defconfig"
KBUILD_DEFCONFIG_qemumips64r6el-nf	= "malta_defconfig"
SRC_URI_append_qemumips64r6el		+= "file://mips64r6el.cfg"
SRC_URI_append_qemumips64r6el-nf	+= "file://mips64r6el.cfg"

# utm8
COMPATIBLE_MACHINE_utm8el	= "utm8el"
COMPATIBLE_MACHINE_utm8		= "utm8"
KBUILD_DEFCONFIG_utm8el		= "cavium_octeon_defconfig"
KBUILD_DEFCONFIG_utm8		= "cavium_octeon_defconfig"
SRC_URI_append_utm8el		+= "file://mips64r2el.cfg"

# sead3_32r6el
COMPATIBLE_MACHINE_sead3-32r6el	= "sead3-32r6el"
KBUILD_DEFCONFIG_sead3-32r6el	= "sead3_defconfig"
SRC_URI_append_sead3-32r6el	+= "file://mips32r6el.cfg"
