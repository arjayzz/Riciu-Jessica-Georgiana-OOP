#pragma once
#include "Volvo.h"

Volvo::Volvo()
{
	capacity = 50;
	consumption = 35;
	rainsp = 60.5;
	snowsp = 45.7;
	sunnysp = 90.2;

}

double Volvo::GetSpeed(Weather w)
{
	return (w == Weather::rain) ? rainsp : ((w == Weather::snow) ? snowsp : sunnysp);
}

int Volvo::GetCapacity()
{
		return capacity;
}

int Volvo::GetConsumption()
{
	return consumption;
}

const char* Volvo::GetBrand()
{
	return "Volvo";
}

