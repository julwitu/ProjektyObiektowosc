#include "Parkingv4.hpp"
#include <iostream>


int main() {
	ParkingLot p(20);
	Car c(VehicleType::car);
	Car c1(VehicleType::car);
	Car c2(VehicleType::car);
	c.parkFirstAvailable(p);
	c1.parkAtChoosen(p, "A18");
	c2.parkAtChoosen(p, "A1");

	c1.clearSpot(p);
}