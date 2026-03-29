#pragma once
#include "Weather.h"
#include <stdlib.h>
#include <iostream>

class Car
{
protected:
	int capacity;
	int consumption;
	double rainsp, sunnysp, snowsp; //km/h
public:
	virtual double GetSpeed(Weather w) = 0;
	virtual int GetCapacity() = 0;
	virtual int GetConsumption() = 0;
	virtual const char* GetBrand() = 0;
};
