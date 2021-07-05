#pragma once
#include <iostream>
#include "AbstractTarget.h"
using std::string;
// клас стрільця
class Shooter
{
public:
	Shooter();
	Shooter(string name);

	// геттери
	string GetName() const;
	float GetShotsRate() const;

	// сеттери
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


