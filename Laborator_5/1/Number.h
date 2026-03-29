#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
class Number
{
	char* val;
	int baseval;
	int count;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	Number(const char* value);
	~Number();

	friend Number operator+(const Number& nr1, const Number& nr2);
	friend Number operator-(const Number& nr1, const Number& nr2);
	char operator[](int i);
	
	Number& operator=(const Number& nr);
	Number& operator=(int nr);
	Number& operator=(const char* nr);
	
	bool operator>(const Number& nr1);
	bool operator<(const Number& nr1);
	bool operator>=(const Number& nr1);
	bool operator<=(const Number& nr1);
	bool operator==(const Number& nr1);
	
	void operator--();
	void operator--(int val);
	void operator +=(const Number& nr);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	
	Number(const Number& other);
	Number(Number&& other);

};