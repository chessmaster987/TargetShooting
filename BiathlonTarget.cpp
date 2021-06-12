#include "BiathlonTarget.h"
#include <iostream>

float BiathlonTarget::shot(int x, int y)
{
    if (currentShotsCount == getMaxShotsCount())
        std::cout << "It`s impossible to shot as max shot count is reached!\n";
    ++currentShotsCount;

    int maxRange = 5; 

    if(abs(x) > maxRange && abs(y) > maxRange)
    return 0;

    if (x == 0 && y == 0)
        return 7;

    if (x == 0 && abs(y) == maxRange || y == 0 && abs(x) == maxRange)
        return 1.5;
    
    return 3;
}

size_t BiathlonTarget::getMaxShotsCount()
{
    return 12;
}
