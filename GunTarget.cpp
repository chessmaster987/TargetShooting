#include "GunTarget.h"

#include <cmath>

GunTarget::GunTarget() : AbstractTarget() {}

GunTarget::GunTarget(size_t maxShotsCount, int maxRange) : AbstractTarget(maxShotsCount, maxRange) {}

float GunTarget::Shot(int x, int y)
{
	++currentShotsCount;

	const int radiusSquared = x * x + y * y;
	const int maxRadiusSquared = maxRange * maxRange;

	if (radiusSquared > maxRadiusSquared)
	{
		return 0;
	}

	const int radius = static_cast<int>(std::round(std::sqrt(static_cast<double>(radiusSquared))));

	if (radius >= maxRange)
	{
		return 0;
	}

	if (radius >= 8)
	{
		return 1;
	}

	if (radius >= 4)
	{
		return 2;
	}

	if (radius >= 2)
	{
		return 3;
	}

	if (radius == 1)
	{
		return 4;
	}

	return 5;
}
