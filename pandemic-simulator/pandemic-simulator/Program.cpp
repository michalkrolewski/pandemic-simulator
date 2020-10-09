#include <iostream>
#include <map> 
#include <list> 
#include <chrono> 

#include "windows.h" 
#include "Person.h" 
#include "Field.h" 
#include "NeighbourhoodCalculator.h"


using namespace std::chrono;
using namespace std;


void printField(map<int, Person*> people, Field field) {

	int columnCounter = 1;

	for (map<int, Person*>::iterator person = people.begin(); person != people.end(); ++person)
	{
		if (person->second->isInfected) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "X ";
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
			cout << "O ";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		if (columnCounter++ == field.width) {
			cout << endl;
			columnCounter = 1;
		}
	}
}


template <typename T>
bool contains(list<T>& listOfElements, const T& element)
{
	auto it = std::find(listOfElements.begin(), listOfElements.end(), element);
	return it != listOfElements.end();
}

int main() {
	srand(time(NULL));
	int INFECTED_CUNT = 1625;
	Field field;
	NeighbourhoodCalculator calculator =  NeighbourhoodCalculator();

	int x = field.width * field.height;
	map<int, Person*> people;

	for (int i = 1; i < x; i++)
	{
		if (i == INFECTED_CUNT) {
			people.insert(pair<int, Person*>(i, new Person(i, true)));
		}
		else {
			people.insert(pair<int, Person*>(i, new Person(i)));
		}
	}

	people.insert(pair<int, Person*>(x, new Person(x)));

	printField(people, field);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "infected people: 1" << endl;
	Sleep(1000);
	int iteration = 1;
	while (true)
	{
		auto start = high_resolution_clock::now();
		int infected = 0;
		list<Person*> neighboursToInfect;
		for (map<int, Person*>::iterator person = people.begin(); person != people.end(); ++person)
		{
			person->second->controlHealthStatus();

			if (person->second->isInfected) {
				infected++;
				list<Person*> neighbours = calculator.calculateMooreNeighbours(people, person->second, field);

				for (list<Person*>::iterator neighbour = neighbours.begin(); neighbour != neighbours.end(); ++neighbour)
				{
					if (!contains(neighboursToInfect, (*neighbour)))
					{
						neighboursToInfect.push_back(*neighbour);
					}
				}

				neighbours = calculator.calculateNeummannNeighbours(people, person->second, field);

				for (list<Person*>::iterator neighbour = neighbours.begin(); neighbour != neighbours.end(); ++neighbour)
				{
					if (!contains(neighboursToInfect, (*neighbour)))
					{
						neighboursToInfect.push_back(*neighbour);
					}
				}
			}
		}

		for (list<Person*>::iterator neighbour = neighboursToInfect.begin(); neighbour != neighboursToInfect.end(); ++neighbour)
		{
			(*neighbour)->markAsInfected();
			infected++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		auto stop = high_resolution_clock::now();
		system("cls");
		printField(people, field);
		cout << endl;
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "Iteration duration: " << duration.count() << " ms" << endl;
		cout << "Iteration: " << ++iteration<< endl;
		cout << "Infected people: " << infected << endl;
	//	Sleep(1000);

	}
	return 0;
}





