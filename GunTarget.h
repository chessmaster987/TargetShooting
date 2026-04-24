#pragma once
#include "AbstractTarget.h"
// Rifle shooting target
class GunTarget
	: public AbstractTarget
{
public:
	GunTarget();
	GunTarget(size_t, int);

	float Shot(int x, int y) override;
};
