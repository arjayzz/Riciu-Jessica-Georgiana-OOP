#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat();
	double GetSpeed(Weather w);
	int GetCapacity();
	int GetConsumption();
	const char* GetBrand();
};
