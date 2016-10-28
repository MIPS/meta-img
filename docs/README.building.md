Build Instructions
==================

The following instructions require OE-Core meta and BitBake. Poky provides these
components, however they can be acquired separately.

Initialize a build using the `oe-init-build-env` script. Once initialized
configure `bblayers.conf` by adding the `meta-img` layer. e.g.:

	BBLAYERS ?= " \
		<path to layer>/oe-core/meta \
		<path to layer>/meta-img \
		"

This can also be done using bitbake-layers add-layer <path to layer>.
		
To build a specific target BSP configure the associated machine in `local.conf`:

	MACHINE ?= "ci40"

Build the target file system image using `bitbake`:

	$ bitbake core-image-minimal

Once complete the images for the target machine will be available in the output
directory `tmp/deploy/images/<machine name>/`.