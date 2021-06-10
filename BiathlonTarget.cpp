#include "BiathlonTarget.h"
#include <iostream>

int BiathlonTarget::shot(int x, int y)
{
    if (currentShotsCount == getMaxShotsCount())
        std::cout << "It`s impossible to shot as max shot count is reached!\n";
    ++currentShotsCount;
    int maxRange = 10;
    if(abs(x) > maxRange && abs(y) > maxRange)
    return 0;
    int max = abs(x) > abs(y) ? abs(x) : abs(y);
    if (max >= 8)
        return 1;
    if (max >= 5)
        return 2;
    if (max >= 3)
        return 3;
    if (max >= 1)
        return 4;
    return 5;
}

size_t BiathlonTarget::getMaxShotsCount()
{
    return 9;
}
