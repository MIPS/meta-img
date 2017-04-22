# License has been inferred from the fdc_printf.c (where it is stated)
# and copied to a new file
DESCRIPTION = "LibFDC"
LICENSE = "LGPLv2"
LIC_FILES_CHKSUM = "file://COPYING.txt;md5=f0e843e4a839940d9cf8a32529fe357f"

# Use './files/src' directory for now.  No SCM'd version of this library could be found
# online, so it is included with the recipe here with its file that had the license.
SRC_URI = "file://src"

# Set source directory for the make as 'src'
S = "${WORKDIR}/src"

# Based on the source, it directly refers to only the Nexys4 DDR configuration
COMPATIBLE_MACHINE = "xilfpga"

# No reason to run configure
do_configure[noexec] = "1"

# Run the standard make
do_compile() {
    oe_runmake
}

# Place the files in the typical locations, the packager will
# automatically pick them up rather than our explicitly defining FILES...
do_install() {
    install -d ${D}${includedir}
    install -m 0644 fdc.h ${D}${includedir}

    install -d ${D}${libdir}
    install -m 0644 libfdc.a ${D}${libdir}
}
