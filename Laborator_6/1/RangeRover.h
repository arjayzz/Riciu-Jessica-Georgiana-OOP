#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
	RangeRover();
	double GetSpeed(Weather w);
	int GetCapacity();
	int GetConsumption();
	const char* GetBrand();
};

