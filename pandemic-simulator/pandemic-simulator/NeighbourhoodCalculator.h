#pragma once
#include <iostream>
#include <map> 
#include <list> 

#include "Person.h"
#include "Field.h"

class NeighbourhoodCalculator
{
public:
	std::list<Person*> calculateNeummannNeighbours(std::map<int, Person*> people, Person* man, Field field);
	std::list<Person*> calculateMooreNeighbours(std::map<int, Person*> people, Person* man, Field field);
};

