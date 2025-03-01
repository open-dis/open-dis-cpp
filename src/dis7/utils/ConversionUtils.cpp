#include "ConversionUtils.h"
#include <cmath>

namespace DIS {

double ConversionUtils::getOrientationFromEuler(double lat, double lon, double psi, double theta)
{
    double sinlat = sin(lat);
    double sinlon = sin(lon);
    double coslon = cos(lon);
    double coslat = cos(lat);
    double sinsin = sinlat * sinlon;

    double cosTheta = cos(theta);
    double cosPsi = cos(psi);
    double sinPsi = sin(psi);
    double sinTheta = sin(theta);

    double cosThetaCosPsi = cosTheta * cosPsi;
    double cosThetaSinPsi = cosTheta * sinPsi;
    double sincos = sinlat * coslon;

    double b11 = -sinlon * cosThetaCosPsi + coslon * cosThetaSinPsi;
    double b12 = -sincos * cosThetaCosPsi - sinsin * cosThetaSinPsi - coslat * sinTheta;

    return radToDeg(atan2(b11, b12)); //range is -pi to pi
}

double ConversionUtils::getPitchFromEuler(double lat, double lon, double psi, double theta)
{
    double sinlat = sin(lat);
    double sinlon = sin(lon);
    double coslon = cos(lon);
    double coslat = cos(lat);
    double cosLatCosLon = coslat * coslon;
    double cosLatSinLon = coslat * sinlon;

    double cosTheta = cos(theta);
    double cosPsi = cos(psi);
    double sinPsi = sin(psi);
    double sinTheta = sin(theta);

    return radToDeg(asin(cosLatCosLon * cosTheta * cosPsi + cosLatSinLon * cosTheta * sinPsi
                         - sinlat * sinTheta));
}

double ConversionUtils::getRollFromEuler(double lat, double lon, double psi, double theta, double phi)
{
    double sinlat = sin(lat);
    double sinlon = sin(lon);
    double coslon = cos(lon);
    double coslat = cos(lat);
    double cosLatCosLon = coslat * coslon;
    double cosLatSinLon = coslat * sinlon;

    double cosTheta = cos(theta);
    double sinTheta = sin(theta);
    double cosPsi = cos(psi);
    double sinPsi = sin(psi);
    double sinPhi = sin(phi);
    double cosPhi = cos(phi);

    double sinPhiSinTheta = sinPhi * sinTheta;
    double cosPhiSinTheta = cosPhi * sinTheta;

    double b23 = cosLatCosLon * (-cosPhi * sinPsi + sinPhiSinTheta * cosPsi)
                 + cosLatSinLon * (cosPhi * cosPsi + sinPhiSinTheta * sinPsi)
                 + sinlat * (sinPhi * cosTheta);

    double b33 = cosLatCosLon * (sinPhi * sinPsi + cosPhiSinTheta * cosPsi)
                 + cosLatSinLon * (-sinPhi * cosPsi + cosPhiSinTheta * sinPsi)
                 + sinlat * (cosPhi * cosTheta);

    return radToDeg(atan2(-b23, -b33));
}
} // namespace DIS
