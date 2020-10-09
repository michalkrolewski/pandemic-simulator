#pragma once
#include <cstdlib>
class Person
{
private:
	static int infectRatio;
	static int fullSicknessTime;
	static int fullHealthinessTime;

public:
	Person(int no, bool pIsInfected);
	Person(int no);
	int number;
	bool isInfected;
	int sicknessTime;
	int healthinessTime;

	bool shouldInfectMooreNeighbour();
	bool shouldInfectNeumannNeighbour();
	bool canBeInfected();
	void controlHealthStatus();
	void markAsInfected();


	void setInfect();
	void setHealthy();

};

