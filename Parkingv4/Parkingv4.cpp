#include "Parkingv4.hpp"
#include <iostream>
#include <string>

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(VehicleType _vt) : vt(_vt) {}
Vehicle::Vehicle(const Vehicle& other)
{
	this->vt = other.vt;
	this->myParkingSpot = other.myParkingSpot;
}
Vehicle& Vehicle::operator=(const Vehicle& other)
{
	this->vt = other.vt;
	this->myParkingSpot = other.myParkingSpot;
	return *this;
}
Vehicle::~Vehicle()
{
}

void Car::parkFirstAvailable(ParkingLot& p) {
	std::string result = p.firstFree();
	std::cout << "Parkowanie na pierwszym dostepnym miejscu: " << result << std::endl;
	p.park(result);
	myParkingSpot = result;
	std::cout << "Zaparkowano!" << std::endl;
}

void Car::parkAtChoosen(ParkingLot& p, std::string spot) {

	do {
		if (p.checkIfAvailable(spot)) {
			p.park(spot);
			myParkingSpot = spot;
			std::cout << "Zaparkowano!" << std::endl;
			break;
		}
		else {
			std::cout << "Wprowadzone miejsce jest niedostepne" << std::endl;
			break;
		}
	} while (!p.checkIfAvailable(spot));
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

void ParkingLot::addCar(Car c)
{

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
			std::cout << "Parkowanie na wybranym przez uzytkownika miejscu: " << input << std::endl;
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

Car::Car()
{
}

Car::Car(VehicleType _vt) : Vehicle(_vt)
{
}

Car::~Car()
{
}



