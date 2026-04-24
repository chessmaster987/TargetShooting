#include "BiathlonTarget.h"

#include <cmath>

BiathlonTarget::BiathlonTarget() : AbstractTarget() {}

BiathlonTarget::BiathlonTarget(size_t maxShotsCount, int maxRange) : AbstractTarget(maxShotsCount, maxRange) {}

float BiathlonTarget::Shot(int x, int y)
{
	++currentShotsCount;

	if (std::abs(x) > maxRange || std::abs(y) > maxRange)
	{
		return 0;
	}

	if (x == 0 && y == 0)
	{
		return 7;
	}

	if ((x == -maxRange && y == 0) ||
		(x == 0 && y == -maxRange) ||
		(x == maxRange && y == 0) ||
		(x == 0 && y == maxRange))
	{
		return 1.5f;
	}

	return 3;
}
