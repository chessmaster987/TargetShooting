#include "AbstractTarget.h"

#include <stdexcept>

AbstractTarget::AbstractTarget() : currentShotsCount(0), maxShotsCount(0), maxRange(0) {}

AbstractTarget::AbstractTarget(size_t maxShotsCount, int maxRange)
	: currentShotsCount(0), maxShotsCount(maxShotsCount), maxRange(maxRange) {}

bool AbstractTarget::canShot() const
{
	if (currentShotsCount > maxShotsCount)
	{
		throw std::logic_error("Current shots count exceeded the target limit.");
	}

	return currentShotsCount < maxShotsCount;
}

size_t AbstractTarget::GetMaxShotsCount() const
{
	return maxShotsCount;
}

int AbstractTarget::GetMaxRange() const
{
	return maxRange;
}

void AbstractTarget::SetMaxShotsCount(size_t maxShotsCount)
{
	this->maxShotsCount = maxShotsCount;
}

void AbstractTarget::SetMaxRange(int maxRange)
{
	this->maxRange = maxRange;
}
