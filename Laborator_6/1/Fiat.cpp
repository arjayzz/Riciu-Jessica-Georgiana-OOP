#include "Fiat.h"

Fiat::Fiat()
{
	capacity = 45;
	consumption = 50;
	rainsp = 55.2;
	snowsp = 40.5;
	sunnysp = 82.7;

}

double Fiat::GetSpeed(Weather w)
{
	return (w == Weather::rain) ? rainsp : ((w == Weather::snow) ? snowsp : sunnysp);
}

int Fiat::GetCapacity()
{
	return capacity;
}

int Fiat::GetConsumption()
{
	return consumption;
}

const char* Fiat::GetBrand()
{
	return "Fiat";
}

