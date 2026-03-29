#include "Circuit.h"

Circuit::Circuit()
{
	count = 0;
	len = 0;
	w = Weather::sunny;
	cararr = new Car*[100];
	time = new double[100];
 }

void Circuit::SetLength(int val)
{
	len = val;
}

void Circuit::AddCar(Car* brand)
{
	if (count < 100)
	cararr[count++] = brand;
}

void Circuit::SetWeather(Weather val)
{
	w = val;
}

//--------------------------------------------

void Circuit::Race()
{
	double speed, consumption, capacity, fuel;

	for (int i = 0; i < count; i++)
	{
		speed = cararr[i]->GetSpeed(w);
		consumption = cararr[i]->GetConsumption();
		capacity = cararr[i]->GetCapacity();

		fuel = (len * consumption) / 100.0;

		if (fuel <= capacity)
			time[i] = (double)len / speed;
		else
			time[i] = -1.0;
	}
}

void Circuit::ShowFinalRanks()
{
	bool swap = true;
	double aux;
	Car* auxcar;


	for (int i = 0; i < count; i++)
	{
		swap = false;
		for (int j = 0; j < count - i - 1; j++)
		{
			if ((time[j] > time[j+1]) && (time[j] > 0))
			{
				aux = time[j];
				time[j] = time[j + 1];
				time[j + 1] = aux;

				auxcar = cararr[j];
				cararr[j] = cararr[j+1];
				cararr[j] = auxcar;

				swap = true;
			}
		}

		if (!swap)
			break;
	}

	for (int i = 0; i < count; i++)
		if (time[i] > 0)
			printf("The %s car finished in %.2f time\n", cararr[i]->GetBrand(), time[i]);
}

void Circuit::ShowWhoDidNotFinish()
{
	printf("The cars that did not finish are:\n");
	for (int i = 0; i < count; i++)
		if (time[i] < 0)
			printf("%s\n", cararr[i]->GetBrand());

}

//----------------------------------------------
Circuit::~Circuit()
{
	for (int i = 0; i < count; i++)
		delete cararr[i];
	count = 0;
	delete[] cararr;
	delete[] time;
}