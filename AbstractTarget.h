#pragma once
// абстрактна мішень
class AbstractTarget
{
public:

	bool canShot();
	virtual float shot(int x, int y) abstract;
	virtual size_t getMaxShotsCount() abstract;

protected:
	size_t currentShotsCount = 0;
};
