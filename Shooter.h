#pragma once
#include <iostream>
using std::string;
// клас стрільця
class Shooter
{
public:
	Shooter();
	Shooter(string name);

	// геттери
	string getName() const;
	float getShotsRate() const;
	// сеттери
	void setName(string name);
	void setShotsRate(float shotsRate);

	void addShotsRate(float rate);


private:
	string name;
	float shotsRate;
};


