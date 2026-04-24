#pragma once

#include <string>

#include "AbstractTarget.h"

using std::string;

class Shooter
{
public:
	Shooter();
	Shooter(string name);

	string GetName() const;
	float GetShotsRate() const;

	void SetName(string name);
	void SetShotsRate(float shotsRate);
	void SetTarget(AbstractTarget* target);

	void AddShotsRate(float rate);

	float Shot(int& x, int& y);

private:
	string name;
	float shotsRate;
	AbstractTarget* target;
};
