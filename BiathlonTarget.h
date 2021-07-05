#pragma once
#include "AbstractTarget.h"
// біатлонна мішень
class BiathlonTarget :
	public AbstractTarget
{
public:
	BiathlonTarget();
	BiathlonTarget(size_t, int);
	float Shot(int x, int y)  override;
	//size_t getMaxShotsCount() const override;
};



