/***
 * IIR Filter Library - Definitions and constants
 *
 * Copyright (C) 2016  Martin Vincent Bloedorn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <cmath>
#include <cstdint>

namespace IIR {
  const uint8_t MAX_ORDER = 5;
  enum ORDER  {OD1 = 0, OD2, OD3, OD4};//, OD5};
  enum TYPE   {LOWPASS = 0, HIGHPASS = 1};
  const float_t SQRT2 = sqrt(2.0);
  const float_t SQRT3 = sqrt(3.0);
  const float_t SQRT5 = sqrt(5.0);
  const float_t EPSILON = 1e-9;
  const float_t WEPSILON = 1e-3;
  const float_t KM = 1.0; // Set to 1000.0 for better numerical precision on 8-bit micros
}
