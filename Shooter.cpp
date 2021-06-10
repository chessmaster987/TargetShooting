#include "Shooter.h"

Shooter::Shooter()
{
	setName("No name");
	setShotsRate(0);
}

Shooter::Shooter(string name)
{
	setName(name);
	setShotsRate(0);
}

string Shooter::getName() const
{
	return name;
}

float Shooter::getShotsRate() const
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

void Shooter::setShotsRate(float shotsRate)
{
	this->shotsRate = shotsRate;
}

void Shooter::addShotsRate(float rate)
{
	shotsRate += rate;
}
