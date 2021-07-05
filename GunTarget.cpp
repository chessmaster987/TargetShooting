#include "GunTarget.h"
#include <iostream>
using namespace std;

GunTarget::GunTarget(): AbstractTarget() {}
GunTarget::GunTarget(size_t maxShotsCount, int maxRange): AbstractTarget(maxShotsCount, maxRange) {}

float GunTarget::Shot(int x, int y)
{
    /*if (currentShotsCount == getMaxShotsCount())
        std::cout << "It`s impossible to shot as max shot count is reached!\n";*/
        ++currentShotsCount;

    //int maxRange = 7;
    if (x*x + y*y > maxRange*maxRange)
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

/*size_t GunTarget::getMaxShotsCount() const
{
    return 21;
}*/

/*6 секторів: 0, 1-2, 3-6, 7-8, 9, 10.
 І тоді розподіл балів за влучання в сектор можна зробити як: 
 0=0 балів, 1-2 = 1 бал, 3-6 = 2 бали, 7-8 = 3 бали, влучання в 9 = 4 бали і в 10 = 5 балів. 
 */
