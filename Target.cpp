#include "Target.h"
using namespace std;
Target::Target()
{
    //ctor
}
Target::Target(int x, int y, int score, bool shot)
    : m_Shot(shot), m_score(score), m_IsCanShot, m_coordinates
{
    if (Shot)
    {
        ;
    }
}

Target::Target(int x, int y, int score, bool shot)
    : m_Shot(shot), m_score(score), m_IsCanShot, m_coordinates
{
    if (Coordinates < 0)
    {
        throw invalid_argument();
    }
}

Target::Target(int x, int y, int score, bool shot)
    : m_Shot(shot), m_score(score), m_IsCanShot, m_coordinates
{
    if (IsCanShot)
    {
        ;
    }
}


std::string Target::Info() const
{
    return "Hit: " + GetShot() + (" + to_string(GetScore()) + " score)";
}