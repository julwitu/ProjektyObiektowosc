#pragma once
#include <string>
enum class VehicleType { car, bus };
class ParkingLot;

class Vehicle {
	VehicleType vt;
protected:
	std::string myParkingSpot;
public:
	Vehicle(VehicleType _vt);
	virtual void whereToPark(ParkingLot& p) = 0; // zapytaj uzytkownika czy chce zaparkowac na pierwszym wolnym miejscu czy wskazanym przez siebie;
	virtual void parkFirstAvailable(ParkingLot& p) = 0; //zaparkuj na pierwszym wolnym
	virtual void parkAtChoosen(ParkingLot& p) = 0; // zaparkuj na wybranym przez siebie
	virtual void clearSpot(ParkingLot& p) = 0; // wyczysc miejsce po sobie;
};

class ParkingLot {
	std::string* parkingSpots = nullptr;
	bool* freeSpots = nullptr;
	int numOfSpots;
public:
	ParkingLot(int numOfSpots);
	void park(std::string input); // zaparkuj - odejmij od tablicy
	std::string firstFree(); // podaj pierwszy wolny
	bool checkIfAvailable(std::string input); // sprawdz czy wybrany jest wolny
	void freeTheSpot(std::string spot); // zwolnij miejsce na parkingu
	void printSpots();
	~ParkingLot();
};

class Car : public Vehicle {
public:
	Car(VehicleType _vt);
	void whereToPark(ParkingLot& p);
	void parkFirstAvailable(ParkingLot& p) override;
	void parkAtChoosen(ParkingLot& p) override;
	void clearSpot(ParkingLot& p) override;

};



