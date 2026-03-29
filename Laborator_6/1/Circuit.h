#pragma once
#include "Car.h"
class Circuit
{
	Car** cararr;
	int count, len;
	double* time;
	Weather w;

public:
	void SetLength(int val);
	void AddCar(Car* brand);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void SetWeather(Weather val);

	Circuit();
	~Circuit();
};
