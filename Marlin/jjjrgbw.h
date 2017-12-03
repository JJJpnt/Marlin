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
 * jjjrgbw.h - Library for controlling RGBWs leds with a custom made
 *             ATmega328P controller over software emulated i2c using
 *             the SoftI2CMaster library by Tod E. Kurt
 *             (couldn't get hardware i2c to work with MKS Base board)
 *
 * Created by Jean-Julien JUPINET, December 03 2017.
 */

#include "Arduino.h"
#include "SoftI2CMaster.h"

#if !PIN_EXISTS(JJJRGBW_SCL) || !PIN_EXISTS(JJJRGBW_SDA)
	#error "JJJRGBW_SCL and JJJRGBW_SDA are not defined !!! See in Configuration.h"
#endif

//JJJ JJJRGBW values for lcd menu
//uint8_t jjjrgbw_r_value, jjjrgbw_g_value, jjjrgbw_b_value;

extern SoftI2CMaster softI2c;

void SendColors(uint8_t red, uint8_t grn, uint8_t blu);
void SendColors(uint8_t white);

