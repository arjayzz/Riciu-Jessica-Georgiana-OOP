#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
	Volvo();
	double GetSpeed(Weather w);
	int GetCapacity();
	int GetConsumption();
	const char* GetBrand();
};
