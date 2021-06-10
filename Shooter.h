#pragma once
#include <iostream>
using std::string;
// клас стрільця
class Shooter
{
public:
	Shooter(string name);

	// геттери
	string getName() const;
	size_t getShotsRate() const;
	// сеттери
	void setName(string name);
	void setShotsRate(size_t shotsRate);

	void addShotsRate(size_t rate);


private:
	string name;
	size_t shotsRate;
};

