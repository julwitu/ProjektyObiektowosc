#include "Parkingv3.hpp"
#include <iostream>
#include <string>

Vehicle::Vehicle(VehicleType _vt) : vt(_vt) {};

void Car::parkFirstAvailable(ParkingLot& p) {
	std::string result = p.firstFree();
	std::cout << "Parkowanie na pierwszym dostepnym miejscu: " << result << std::endl;
	p.park(result);
	myParkingSpot = result;
	std::cout << "Zaparkowano!" << std::endl;
}

void Car::parkAtChoosen(ParkingLot& p) {
	std::string input;
	do {
		std::cout << "W jakim miejscu chcesz zaparkowac?  ";
		std::cin >> input;
		if (p.checkIfAvailable(input)) {
			p.park(input);
			myParkingSpot = input;
			std::cout << "Zaparkowano!" << std::endl;
			break;
		}
		else {
			std::cout << "Wprowadzone miejsce jest niedostepne" << std::endl;
		}
	} while (!p.checkIfAvailable(input));
}
void Car::clearSpot(ParkingLot& p) {
	p.freeTheSpot(myParkingSpot);
}

void ParkingLot::printSpots() {
	const std::string red("\033[0;31m");
	const std::string green("\033[0;32m");
	const std::string reset("\033[0m");

	for (int i = 0; i < numOfSpots; i++) {
		if (freeSpots[i]) {
			std::cout << green << parkingSpots[i] << " ";
		}
		else {
			std::cout << red << parkingSpots[i] << " ";
		}
	} std::cout << reset << std::endl;
}

ParkingLot::ParkingLot(int numOfSpots) {

	parkingSpots = new std::string[numOfSpots];
	freeSpots = new bool[numOfSpots];
	this->numOfSpots = numOfSpots;
	std::cout << "Dostepne miejsca parkingowe:" << std::endl;
	for (int i = 0; i < numOfSpots; i++) {
		parkingSpots[i] += "A" + std::to_string(i + 1);
		freeSpots[i] = true;
	}

	//dla sprawdzenie zmienilam linie 58 jest freeSpots[i] = false i dodalam jakies losowe freeSpots, zeby byly true;
	//freeSpots[3] = true;
	//freeSpots[7] = true;
	//freeSpots[2] = true;
	//freeSpots[8] = true;
	//freeSpots[1] = true;
	//freeSpots[6] = true;

	printSpots();
}

void ParkingLot::park(std::string input) {
	for (int i = 0; i < numOfSpots; i++) {
		if (parkingSpots[i] == input) {
			freeSpots[i] = false;
		}
	}
	printSpots();

}

std::string ParkingLot::firstFree() {
	int index = 0;
	for (int i = 0; i < numOfSpots; i++) {
		if (freeSpots[i] == true) {
			index = i;
			break;
		}
	}
	return parkingSpots[index];
}

bool ParkingLot::checkIfAvailable(std::string input)
{
	bool isFree = false;
	for (int i = 0; i < numOfSpots; i++) {
		if ((parkingSpots[i] == input) && (freeSpots[i] == true)) {
			isFree = true;
		}
	}
	return isFree;
}
void ParkingLot::freeTheSpot(std::string spot) {
	for (int i = 0; i < numOfSpots; i++) {
		if (parkingSpots[i] == spot) {
			freeSpots[i] = true;
		}
	}
	printSpots();
}
ParkingLot::~ParkingLot()
{
	delete[] parkingSpots;
	parkingSpots = nullptr;
	delete[] freeSpots;
	freeSpots = nullptr;
}

Car::Car(VehicleType _vt) : Vehicle(_vt)
{
}

void Car::whereToPark(ParkingLot& p)
{
	int result = 0;
	std::cout << "Zaparkuj na pierwszym wolnym miejscu (wpisz: '1') : Zaparkuj na wskazanym przez siebie (wpisz: '2')" << std::endl;
	std::cin >> result;
	if (result == 1) {
		parkFirstAvailable(p);
	}
	else if (result == 2) {
		parkAtChoosen(p);
	}

	char leaveSpot = 'N';
	std::cout << "Czy chcesz zwolnic miejsce? (T/N)" << std::endl;
	std::cin >> leaveSpot;
	if (leaveSpot == 'T') {
		clearSpot(p);
	}
	else {
		p.printSpots();
	}
}


