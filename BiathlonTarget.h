#pragma once
#include "AbstractTarget.h"
// Biathlon target
class BiathlonTarget :
	public AbstractTarget
{
public:
	BiathlonTarget();
	BiathlonTarget(size_t, int);
	float Shot(int x, int y)  override;
};



