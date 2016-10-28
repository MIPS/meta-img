DESCRIPTION = "Closed source binary firmware for the uccp420 wlan on the Ci40"
LICENSE = "CLOSED"

COMPATIBLE_MACHINE = "ci40"

# WiFi firmware version 6.0.4 from https://github.com/CreatorDev/openwrt/blob/target/linux/pistachio/base-files/lib/firmware/img/uccp420wlan/

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI =  "file://MAC_LOADER.ldr;name=MAC_LOADER;"
SRC_URI += "file://MCP_LOADER.ldr;name=MCP_LOADER;"

SRC_URI[MAC_LOADER.md5sum] = "90d45fdabe671ac84c23584022110391"
SRC_URI[MAC_LOADER.sha256sum] = "084c9ec49fd459d2b81926c26e81e427a0de64f30529ad52c9d17cb5dc526248"

SRC_URI[MCP_LOADER.md5sum] = "d3197e5156eb936c94547eda2447798e"
SRC_URI[MCP_LOADER.sha256sum] = "d235846a2a25e23d78a1fb0460561f7811fbeda90c1701f189ec93e8322ce330"

do_install() {
	install -d ${D}/lib/firmware/img/uccp420wlan
	install -m 0644 ${THISDIR}/files/MAC_LOADER.ldr ${D}/lib/firmware/img/uccp420wlan/MAC_LOADER.ldr
	install -m 0644 ${THISDIR}/files/MCP_LOADER.ldr ${D}/lib/firmware/img/uccp420wlan/MCP_LOADER.ldr
}

FILES_${PN} += "/lib/firmware/img/uccp420wlan"
