/*
 * Atheros PHY drivers
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * Copyright 2011 Freescale Semiconductor, Inc.
 * author Andy Fleming
 *
 */
#include <phy.h>

static int ar8021_config(struct phy_device *phydev)
{
	phy_write(phydev, MDIO_DEVAD_NONE, 0x1d, 0x05);
	phy_write(phydev, MDIO_DEVAD_NONE, 0x1e, 0x3D47);

	return 0;
}

static struct phy_driver AR8021_driver =  {
	.name = "AR8021",
	.uid = 0x4dd040,
	.mask = 0xfffff0,
	.features = PHY_GBIT_FEATURES,
	.config = ar8021_config,
	.startup = genphy_startup,
	.shutdown = genphy_shutdown,
};

static int ar8031_config(struct phy_device *phydev)
{
	int val;

	/* To enable AR8031 output a 125MHz clk from CLK_25M */
	phy_write(phydev, MDIO_DEVAD_NONE, 0xd, 0x07);
	phy_write(phydev, MDIO_DEVAD_NONE, 0xe, 0x8016);
	phy_write(phydev, MDIO_DEVAD_NONE, 0xd, 0x4007);

	val = phy_read(phydev, MDIO_DEVAD_NONE, 0xe);
	val &= 0xffe3;
	val |= 0x18;
	phy_write(phydev, MDIO_DEVAD_NONE, 0xe, val);

	/* introduce tx clock delay */
	phy_write(phydev, MDIO_DEVAD_NONE, 0x1d, 0x5);
	val = phy_read(phydev, MDIO_DEVAD_NONE, 0x1e);
	val |= 0x0100;
	phy_write(phydev, MDIO_DEVAD_NONE, 0x1e, val);


	return 0;
}

static struct phy_driver AR8031_driver =  {
	.name = "AR8031",
	.uid = 0x4dd074,
	.mask = 0xfffff0,
	.features = PHY_GBIT_FEATURES,
	.config = ar8031_config,
	.startup = genphy_startup,
	.shutdown = genphy_shutdown,
};


int phy_atheros_init(void)
{
	phy_register(&AR8021_driver);
	phy_register(&AR8031_driver);

	return 0;
}
