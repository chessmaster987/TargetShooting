#pragma once
#include "AbstractTarget.h"
// мішень для стрільби з гвинтівки
class GunTarget
	: public AbstractTarget
{
	float shot(int x, int y) override;
	size_t getMaxShotsCount() override;
};

