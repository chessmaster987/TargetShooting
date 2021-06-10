#include "GunTarget.h"
#include <iostream>

int GunTarget::shot(int x, int y)
{
    if (currentShotsCount == getMaxShotsCount())
        std::cout << "It`s impossible to shot as max shot count is reached!\n";
    ++currentShotsCount;
    int maxRange = 7;
    if (abs(x) > maxRange && abs(y) > maxRange)
        return 0;
    int max = abs(x) > abs(y) ? abs(x) : abs(y);
    if (max >= 5)
        return 1;
    if (max == 4)
        return 2;
    if (max == 3)
        return 3;
    if (max >= 1)
        return 4;
    return 5;
}

size_t GunTarget::getMaxShotsCount()
{
    return 11;
}
