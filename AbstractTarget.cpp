#include "AbstractTarget.h"

bool AbstractTarget::canShot()
{
	return currentShotsCount < getMaxShotsCount();
}
