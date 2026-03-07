#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

double Math::Add(double a, double b)
{
	return a + b;
}

double Math::Add(double a, double b, double c)
{
	return a + b + c;
}

 int Math::Mul(int a, int b)
{
	 return a * b;
}

 int Math::Mul(int a, int b, int c)
 {
	 return a * b * c;
}

double Math::Mul(double a, double b)
 {
	 return a * b;
}

double Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++)
		sum = sum + va_arg(args, int);
	va_end(args);
	return sum;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;
	char* c = new char[strlen(a) + strlen(b) + 1];
	strcpy(c, a);
	strcat(c, b);
	return c;
}