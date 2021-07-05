#include "BiathlonTarget.h"
#include <iostream>
using namespace std;

BiathlonTarget::BiathlonTarget(): AbstractTarget() {}
BiathlonTarget::BiathlonTarget(size_t maxShotsCount, int maxRange): AbstractTarget(maxShotsCount, maxRange) {}

float BiathlonTarget::Shot(int x, int y)
{
    /*if (currentShotsCount == GetMaxShotsCount())
        std::cout << "It`s impossible to shot as max shot count is reached!\n"; */
    ++currentShotsCount;

    //int maxRange = 5;

    if(abs(x*x) + abs(y*y) > maxRange * maxRange)
        return 0;

    if (x == 0 && y == 0)
        return 7;

    if (x == 0 && y == maxRange || y == 0 && x == maxRange)
        return 1.5;

    return 3;
}


/*size_t BiathlonTarget::getMaxShotsCount() const
{
    return 12;
}*/

/*Для біатлонної мішені діапазон [-5;5] - є сектором вдалого влучання -- 3 очки
(-5;0),(0;-5),(5;0),(0;5) - 1,5 очки
(0;0) - 7 очків
*/
