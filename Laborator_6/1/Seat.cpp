#include "Seat.h"

Seat::Seat()
{
	capacity = 65;
	consumption = 78;
	rainsp = 64.2;
	snowsp = 47.5;
	sunnysp = 98.2;

}

double Seat::GetSpeed(Weather w)
{
	return (w == Weather::rain) ? rainsp : ((w == Weather::snow) ? snowsp : sunnysp);
}

int Seat::GetCapacity()
{
	return capacity;
}

int Seat::GetConsumption()
{
	return consumption;
}

const char* Seat::GetBrand()
{
	return "Seat";
}

