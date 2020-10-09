#include "Person.h"

int Person::infectRatio = 30;
int Person::fullSicknessTime = 7;
int Person::fullHealthinessTime = 4;

Person::Person(int no, bool pIsInfected)
{
	number = no;
	isInfected = pIsInfected;
	sicknessTime = fullSicknessTime;
	healthinessTime = 0;
}

Person::Person(int no)
{
	number = no;
	isInfected = false;
	sicknessTime = 0;
	healthinessTime = 0;
}

bool Person::shouldInfectMooreNeighbour()
{
	return (rand() % 100 + 1) <= 0.7 * infectRatio;
}

bool Person::shouldInfectNeumannNeighbour()
{
	return (rand() % 100 + 1) <= infectRatio;
}

bool Person::canBeInfected()
{
	return !isInfected && healthinessTime == 0;
}

void Person::controlHealthStatus()
{
	if (isInfected)
	{
		if (sicknessTime == 0) {
			isInfected = false;
			healthinessTime = fullHealthinessTime;
		}
		else {
			sicknessTime--;
		}
	}
	else
	{
		if (healthinessTime > 0) {
			healthinessTime--;
		}
	}
}

void Person::markAsInfected()
{
	isInfected = true;
	sicknessTime = fullSicknessTime;
	healthinessTime = 0;
}

void Person::setInfect()
{
	isInfected = true;
}

void Person::setHealthy()
{
	isInfected = false;
}

