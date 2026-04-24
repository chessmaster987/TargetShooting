#pragma once

#include <cstddef>

class AbstractTarget
{
public:
	AbstractTarget();
	AbstractTarget(size_t maxShotsCount, int maxRange);
	virtual ~AbstractTarget() = default;

	bool canShot() const;

	virtual float Shot(int x, int y) = 0;

	size_t GetMaxShotsCount() const;
	int GetMaxRange() const;

	void SetMaxShotsCount(size_t maxShotsCount);
	void SetMaxRange(int maxRange);

private:
	size_t maxShotsCount;

protected:
	size_t currentShotsCount;
	int maxRange;
};
