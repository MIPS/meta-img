SUMMARY = "Simple GPIO control example"
LICENSE = "CLOSED"

COMPATIBLE_MACHINE = "xilfpga"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI = "file://simple_gpio_on.c"

S = "${WORKDIR}"

do_configure[noexec] = "1"

do_compile() {
    ${CC}  ${CFLAGS} ${LDFLAGS} simple_gpio_on.c -o simple_gpio_on
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 simple_gpio_on ${D}${bindir}
}