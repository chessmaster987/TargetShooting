#include "AbstractTarget.h"

AbstractTarget::AbstractTarget(): currentShotsCount(0){}
AbstractTarget::AbstractTarget(size_t maxShotsCount, int maxRange): currentShotsCount(0), maxShotsCount(maxShotsCount), maxRange(maxRange) {}
bool AbstractTarget::canShot() const
{
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
