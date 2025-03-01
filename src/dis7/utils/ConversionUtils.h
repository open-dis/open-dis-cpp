#pragma once

#include <dis7/opendis7_export.h>

/**
 * This class provides methods to convert Euler angles (i.e., psi, theta, and phi)
 * to Tait-Bryan angles (i.e., roll, pitch, and yaw/heading),
 * given the position (i.e., latitude, longitude).
 *
 *  Converting Euler angles to Tait-Bryan angles: Given latitude and longitude,
 *  it converts psi, theta, and phi to roll, pitch, and yaw.
 *
 * @note
 * - Euler angles (psi, theta, and phi) are always expressed in radians.
 * - Latitude and longitude are also expressed in radians.
 */

namespace DIS {

const double PI = 3.14159265358979;

class OPENDIS7_EXPORT ConversionUtils
{
public:
    /**
     * @brief Gets a degree heading for an entity based on euler angles. All angular
     * values passed in must be in radians.
     * @param lat latitude expressed in radians
     * @param lon longitude expressed in radians
     * @param psi X angle part of Tait-Bryan XYZ convention expressed in radians
     * @param theta Y angle part of Tait-Bryan XYZ convention expressed in radians
     * @return the heading, in degrees, with 0 being north, positive angles
     * going clockwise, and negative angles going counterclockwise (i.e., 90 deg
     * is east, -90 is west)
     */
    static double getOrientationFromEuler(double lat, double lon, double psi, double theta);

    /**
     * @brief Gets a degree pitch for an entity based on euler angles. All angular
     * values passed in must be in radians.
     * @param lat latitude expressed in radians
     * @param lon longitude expressed in radians
     * @param psi X angle part of Tait-Bryan XYZ convention expressed in radians
     * @param theta Y angle part of Tait-Bryan XYZ convention expressed in radians
     * @return the pitch, in degrees, with 0 being level. A negative values is
     * when the entity's nose is pointing downward, positive value is when the
     * entity's nose is pointing upward.
     */
    static double getPitchFromEuler(double lat, double lon, double psi, double theta);

    /**
     * @brief Gets the degree roll for an entity based on euler angles. All angular
     * values passed in must be in radians.
     * @param lat latitude expressed in radians
     * @param lon longitude expressed in radians
     * @param psi X angle part of Tait-Bryan XYZ convention expressed in radians
     * @param theta Y angle part of Tait-Bryan XYZ convention expressed in radians
     * @param phi Z angle part of Tait-Bryan XYZ convention expressed in radians
     * @return the roll, in degrees, with 0 being level flight, + roll is
     * clockwise when looking out the front of the entity.
     */
    static double getRollFromEuler(double lat, double lon, double psi, double theta, double phi);

    static double radToDeg(double rad) { return rad * (180 / PI); };
    static double degToRad(double deg) { return deg * (PI / 180); };
};
} // namespace DIS

// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
//
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
