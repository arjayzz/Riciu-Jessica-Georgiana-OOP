#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
	Fiat();
	double GetSpeed(Weather w);
	int GetCapacity();
	int GetConsumption();
	const char* GetBrand();
};


