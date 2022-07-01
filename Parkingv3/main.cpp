#include "Parkingv3.hpp"
#include <iostream>


int main() {
	ParkingLot p(20);
	Car c(VehicleType::car);
	c.whereToPark(p);

	Car c1(VehicleType::car);
	c1.whereToPark(p);

	Car c2(VehicleType::car);
	c2.whereToPark(p);
	//c.parkFirstAvailable(p);

	//Car c1(VehicleType::bus);
	//c1.parkAtChoosen(p);

	//c1.clearSpot(p);
}