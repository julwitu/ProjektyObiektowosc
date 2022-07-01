#pragma once
#include <string>
enum class VehicleType { car, bus };
class ParkingLot;

class Vehicle {
	VehicleType vt;
protected:
	std::string myParkingSpot;
public:
	Vehicle();
	Vehicle(VehicleType _vt);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	virtual ~Vehicle();
	virtual void parkFirstAvailable(ParkingLot& p) = 0; //zaparkuj na pierwszym wolnym
	virtual void parkAtChoosen(ParkingLot& p, std::string spot) = 0; // zaparkuj na wybranym przez siebie
	virtual void clearSpot(ParkingLot& p) = 0; // wyczysc miejsce po sobie;
};

class Car : public Vehicle {
public:
	Car();
	Car(VehicleType _vt);
	~Car();
	void parkFirstAvailable(ParkingLot& p) override;
	void parkAtChoosen(ParkingLot& p, std::string spot) override;
	void clearSpot(ParkingLot& p) override;
};

class ParkingLot {
	std::string* parkingSpots = nullptr;
	bool* freeSpots = nullptr;
	int numOfSpots;
	Car* cars = new Car[numOfSpots];;
public:
	ParkingLot(int numOfSpots);
	void park(std::string input); // zaparkuj - odejmij od tablicy
	std::string firstFree(); // podaj pierwszy wolny
	bool checkIfAvailable(std::string input); // sprawdz czy wybrany jest wolny
	void freeTheSpot(std::string spot); // zwolnij miejsce na parkingu
	void printSpots();
	void addCar(Car c);
	virtual ~ParkingLot();
};



