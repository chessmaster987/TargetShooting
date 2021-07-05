#include "Shooter.h"

Shooter::Shooter(): name("No name"), shotsRate(0) {}

Shooter::Shooter(string name): name(name), shotsRate(0) {}

string Shooter::GetName() const
{
	return name;
}

float Shooter::GetShotsRate() const{
	return shotsRate;
}

void Shooter::SetName(string name){
	if (name.empty())
		this->name = "no name";
	else
		this->name = name;
}

void Shooter::SetShotsRate(float shotsRate){
	this->shotsRate = shotsRate;
}

void Shooter::AddShotsRate(float rate){
	shotsRate += rate;
}

float Shooter::Shot(int& x, int& y){
	x = y = (rand() % 40) - 20;
	float scores = target->Shot(x, y);
	shotsRate += scores;
	return scores;
}
void Shooter::SetTarget(AbstractTarget* target){
	this->target = target;
}
