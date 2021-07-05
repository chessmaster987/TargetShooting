#pragma once
#include "AbstractTarget.h"
// мішень для стрільби з гвинтівки
class GunTarget
	: public AbstractTarget
{
public:
	GunTarget();
	GunTarget(size_t, int);

	float Shot(int x, int y) override;
	//size_t getMaxShotsCount() const override;
};
