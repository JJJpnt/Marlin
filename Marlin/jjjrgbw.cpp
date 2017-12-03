/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * jjjrgbw.cpp - Library for controlling RGBWs leds with a custom made
 *               ATmega328P controller over software emulated i2c using
 *               the SoftI2CMaster library by Tod E. Kurt
 *               (couldn't get hardware i2c to work with MKS Base board)
 *
 * Created by Jean-Julien JUPINET, December 03 2017.
 */

#include "Marlin.h"

#if ENABLED(JJJRGBW)

#include "jjjrgbw.h"

//JJJ JJJRGBW values for lcd menu
uint8_t jjjrgbw_r_value = 0;  //JJJ JJJRGBW r value
uint8_t jjjrgbw_g_value = 0;  //JJJ JJJRGBW g value
uint8_t jjjrgbw_b_value = 0;  //JJJ JJJRGBW b value

void SendColors(uint8_t red, uint8_t grn, uint8_t blu) {

	SoftI2CMaster softI2c(JJJRGBW_SCL_PIN, JJJRGBW_SDA_PIN, true);
	softI2c.beginTransmission(0x09);	//Try to reach 0x09 slave over i2c
	softI2c.write('o');	// "o" reset script - to disable ongoing script, only needs to be used once
	softI2c.write('n');	// "n" set rgb
	softI2c.write(red);
	softI2c.write(grn);
	softI2c.write(blu);
	softI2c.endTransmission();

	jjjrgbw_r_value = red;
	jjjrgbw_g_value = grn;
	jjjrgbw_b_value = blu;

	#if ENABLED(JJJRGBW_DEBUG)
		  SERIAL_ECHO("JJJRGBW: SendColors(");
		  SERIAL_ECHOPAIR(" red=", red);
		  SERIAL_ECHOPAIR(", grn=", grn);
		  SERIAL_ECHOPAIR(", blu=", blu);
		  SERIAL_ECHO(" ) \n");
	#endif
}

void SendColors(uint8_t whi) {

	SoftI2CMaster softI2c(JJJRGBW_SCL_PIN, JJJRGBW_SDA_PIN, true);
	softI2c.beginTransmission(0x09);	//Try to reach 0x09 slave over i2c
	softI2c.write('o');	// "o" reset script - to disable ongoing script, only needs to be used once
	softI2c.write('w');	// "n" set w
	softI2c.write(whi);
	softI2c.endTransmission();
	SERIAL_ECHO("SendColors : I2C > WHITE < ");
	SERIAL_ECHOPAIR("white : ", whi);
	SERIAL_ECHO("> \n");
	#if ENABLED(JJJRGBW_DEBUG)
		  SERIAL_ECHO("JJJRGBW: SendColors(");
		  SERIAL_ECHOPAIR(" whi=", whi);
		  SERIAL_ECHO(" ) \n");
	#endif
}

#endif // JJJRGBW
