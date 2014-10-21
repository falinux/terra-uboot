

uboot 사용법

1. git clone git://git.denx.de/u-boot.git


2. cd u-boot-imx6-denx/


3. patch -p1 < ../patch-ezboard/00xx-abcdefg.patch
   patch -p1 < ../patch-ezboard/00xx-abcdefg.patch
   ...
   ...
   patch -p1 < ../patch-ezboard/00xx-abcdefg.patch


4. 설정 방벙

	4.1  sabrelite 보드의 경우
		make mx6qsabrelite_config

	4.1  ez-imx6 보드의 경우
		make mx6qsabrelite-ez

	4.2  ez-imx6 보드의 경우 4G 지원 모델
		make mx6qsabrelite-ez-4G


5. 컴파일 방법
	make u-boot.imx


board/freescale/mx6qsabrelite/README 참조...

sudo dd if=u-boot.imx of=/dev/sXx bs=512 seek=2&&sudo sync
