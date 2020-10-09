#include "NeighbourhoodCalculator.h"

std::list<Person*> NeighbourhoodCalculator::calculateNeummannNeighbours(std::map<int, Person*> people, Person* man, Field field)
{

	int number = man->number;
	std::list<Person*> neighbours;

	int tmp = number + field.width;
	if (tmp < field.size()) {
		Person* neighbour = people.find(tmp)->second;
		if (neighbour->canBeInfected() && man->shouldInfectNeumannNeighbour()) {
			neighbours.push_back(neighbour);
		}
	}

	tmp = number - field.width;
	if (tmp > 0) {
		Person* neighbour = people.find(tmp)->second;
		if (neighbour->canBeInfected() && man->shouldInfectNeumannNeighbour()) {
			neighbours.push_back(neighbour);
		}
	}

	tmp = number + 1;
	if (number % field.width != 0) {
		Person* neighbour = people.find(tmp)->second;
		if (neighbour->canBeInfected() && man->shouldInfectNeumannNeighbour()) {
			neighbours.push_back(neighbour);
		}
	}

	tmp = number - 1;
	if (number % field.width != 1) {
		Person* neighbour = people.find(tmp)->second;
		if (neighbour->canBeInfected() && man->shouldInfectNeumannNeighbour()) {
			neighbours.push_back(neighbour);
		}
	}

	return neighbours;
}

std::list<Person*> NeighbourhoodCalculator::calculateMooreNeighbours(std::map<int, Person*> people, Person* man, Field field)
{
	int number = man->number;
	std::list<Person*> neighbours;


	int tmp = number + field.width + 1;
	if (tmp < field.size() && number % field.width != 0) {
		Person* neighbour = people.find(tmp)->second;
		if (neighbour->canBeInfected() && man->shouldInfectMooreNeighbour()) {
			neighbours.push_back(neighbour);
		}
	}

	tmp = number + field.width - 1;
	if (tmp < field.size() && number % field.width != 1) {
		Person* neighbour = people.find(tmp)->second;
		if (neighbour->canBeInfected() && man->shouldInfectMooreNeighbour()) {
			neighbours.push_back(neighbour);
		}
	}


	tmp = number - field.width + 1;
	if (tmp > 0 && number % field.width != 0) {
		Person* neighbour = people.find(tmp)->second;
		if (neighbour->canBeInfected() && man->shouldInfectMooreNeighbour()) {
			neighbours.push_back(neighbour);
		}
	}


	tmp = number - field.width - 1;
	if (tmp > 0 && number % field.width != 1) {
		Person* neighbour = people.find(tmp)->second;
		if (neighbour->canBeInfected() && man->shouldInfectMooreNeighbour()) {
			neighbours.push_back(neighbour);
		}
	}

	return neighbours;
}

