#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW();
	double GetSpeed(Weather w);
	int GetCapacity();
	int GetConsumption();
	const char* GetBrand();
};