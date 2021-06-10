#include "Shooter.h"
Shooter::Shooter(string name)
{
	setName(name);
	setShotsRate(0);
}

string Shooter::getName() const
{
	return name;
}

size_t Shooter::getShotsRate() const
{
	return shotsRate;
}

void Shooter::setName(string name)
{
	if (name.empty())
		this->name = "no name";
	else
		this->name = name;
}

void Shooter::setShotsRate(size_t shotsRate)
{
	this->shotsRate = shotsRate;
}

void Shooter::addShotsRate(size_t rate)
{
	shotsRate += rate;
}


