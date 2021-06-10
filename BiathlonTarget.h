#pragma once
#include "AbstractTarget.h"
// біатлонна мішень
class BiathlonTarget :
    public AbstractTarget
{
public:
	float shot(int x, int y) override;
	size_t getMaxShotsCount() override;
private:
};

