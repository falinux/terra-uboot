#!/bin/sh

image_filename="u-boot.imx"

if [ ! -f include/autoconf.mk ]; then
	echo "...mx6solo HKC-KICAD config"
	make  arm=ARM CROSS_COMPILE=arm-linux-gnueabihf- mx6qsabrelite-ez-4G
#	make arm=ARM CROSS_COMPILE=arm-linux-gnueabihf- mx6qsabrelite_config
fi

if [ "$1" = "" ]; then
	ARCH=arm make arm=ARM CROSS_COMPILE=arm-linux-gnueabihf- 
else
    ARCH=arm make arm=ARM CROSS_COMPILE=arm-linux-gnueabihf- $1 $2 $3
fi

if [ -f $image_filename ]; then
   echo "copy from $image_filename to /tftpboot/$image_filename"
   cp  $image_filename /tftpboot/$image_filename
   chmod 777 /tftpboot/$image_filename
fi
