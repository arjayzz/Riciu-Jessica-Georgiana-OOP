#include "RangeRover.h"

RangeRover::RangeRover()
{
	capacity = 70;
	consumption = 43;
	rainsp = 68.7;
	snowsp = 65.2;
	sunnysp = 89.5;

}

double RangeRover::GetSpeed(Weather w)
{
	return (w == Weather::rain) ? rainsp : ((w == Weather::snow) ? snowsp : sunnysp);
}

int RangeRover::GetCapacity()
{
	return capacity;
}

int RangeRover::GetConsumption()
{
	return consumption;
}

const char* RangeRover::GetBrand()
{
	return "Range Rover";
}

