#include "Shooter.h"

#include <cstdlib>

Shooter::Shooter() : name("no name"), shotsRate(0), target(nullptr) {}

Shooter::Shooter(string name) : name("no name"), shotsRate(0), target(nullptr)
{
	SetName(name);
}

string Shooter::GetName() const
{
	return name;
}

float Shooter::GetShotsRate() const
{
	return shotsRate;
}

void Shooter::SetName(string name)
{
	if (name.empty())
	{
		this->name = "no name";
	}
	else
	{
		this->name = name;
	}
}

void Shooter::SetShotsRate(float shotsRate)
{
	this->shotsRate = shotsRate;
}

void Shooter::SetTarget(AbstractTarget* target)
{
	this->target = target;
}

void Shooter::AddShotsRate(float rate)
{
	shotsRate += rate;
}

float Shooter::Shot(int& x, int& y)
{
	if (target == nullptr)
	{
		return 0;
	}

	x = (rand() % 41) - 20;
	y = (rand() % 41) - 20;

	const float scores = target->Shot(x, y);
	AddShotsRate(scores);
	return scores;
}
