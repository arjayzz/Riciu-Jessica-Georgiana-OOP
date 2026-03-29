#include "BMW.h"

BMW::BMW()
{
	capacity = 55;
	consumption = 20;
	rainsp = 46.5;
	snowsp = 42.7;
	sunnysp = 87.2;

}

double BMW::GetSpeed(Weather w)
{
	return (w == Weather::rain) ? rainsp : ((w == Weather::snow) ? snowsp : sunnysp);
}

int BMW::GetCapacity()
{
	return capacity;
}

int BMW::GetConsumption()
{
	return consumption;
}

const char* BMW::GetBrand()
{
	return "BMW";
}

