#include "Number.h"

int atoic(char* t, int base)
{
	int nr = 0, c, len;
	len = strlen(t);
	int p = 1;
	for (int i = len-1; i >= 0; i--)
	{
		c = (t[i] >= '0' && t[i] <= '9') ? (t[i] - '0') : (t[i] - 'A' + 10);
		nr = nr + c * p;
		p = p * base;
	}
	return nr;
}

char* itoac(int nr, int base)
{
	char aux[100];
	char charc;
	int c, i = 0;
	
	if (nr == 0)
		aux[i++] = '0';

	while (nr != 0)
	{
		c = nr % base;
		aux[i++] = (c < 10) ? (c + '0') : (c - 10 + 'A');
		nr = nr / base;
	}

	char* value;
	int count = i;
	value = new char[count+1];
	for (i = 0; i < count; i++)
		value[i] = aux[count - i - 1];
	value[count] = '\0';
	return value;
}

//-------------------------------------------------------

Number::Number(const char* value, int base)
{

	if (base >= 2 && base <= 16)
		baseval = base;

	count = strlen(value);
	val = new char[count + 1];
	strcpy(val, value);
}

Number::Number(int nr)
{
	baseval = 10;
	val = itoac(nr,10);
	count = strlen(val);
}

Number::Number(const char* nr)
{
	baseval = 10;
	count = strlen(nr);
	val = new char[count + 1];
	strcpy(val, nr);
}

Number::~Number()
{
	delete[] val;
	val = nullptr;
}

int Number::GetDigitsCount()
{
	return count;
}

int Number::GetBase()
{
	return baseval;
}

void Number::Print()
{
		printf("%s", val);
	printf("\n");
}

void Number::SwitchBase(int newBase)
{
	int nr = atoic(val,baseval);
	delete[] val;
	val = itoac(nr, newBase);
	baseval = newBase;
	count = strlen(val);
}
//---------------------------------------------------

char Number::operator [](int i)
{
	if (i >= 0 && i <= count)
		return val[i];
	else
		return val[0];
}

Number operator+(const Number& nr1, const Number& nr2)
{
	int a, b, s, final;
	a = atoic(nr1.val, nr1.baseval);
	b = atoic(nr2.val, nr2.baseval);
	s = a + b;

	final = (nr1.baseval > nr2.baseval) ? nr1.baseval : nr2.baseval;
	
	char* sum = itoac(s, final);

	Number rezultat(sum, final);
	delete[] sum;
	sum = nullptr;

	return rezultat;
}


Number operator-(const Number& nr1, const Number& nr2)
{
	int a, b, d, final;
	a = atoic(nr1.val, nr1.baseval);
	b = atoic(nr2.val, nr2.baseval);
	d = (a > b) ? (a - b) : (b - a);

	final = (nr1.baseval > nr2.baseval) ? nr1.baseval : nr2.baseval;

	char* dif = itoac(d, final);

	Number rezultat(dif, final);
	delete[] dif;
	dif = nullptr;

	return rezultat;
}

Number& Number::operator=(const Number& nr)
{
	delete[] val;
	int final;
	final = (baseval > nr.baseval) ? baseval : nr.baseval;
	baseval = final;
	int num;
	num = atoic(nr.val, final);
	val = itoac(num, final);
	count = strlen(val);
	
	return (*this);
}

Number& Number::operator=(int nr)
{
	delete[] val;
	
	val = itoac(nr, baseval);
	count = strlen(val);

	return (*this);
}

Number& Number::operator=(const char* nr)
{
	delete[] val;
	baseval = 10;
	count = strlen(nr);
	val = new char[count + 1];
	strcpy(val, nr);
	return (*this);
}

bool Number::operator<(const Number& nr)
{
	int a, b;
	a = atoic(val, baseval);
	b = atoic(nr.val, nr.baseval);
	return a < b;
}

bool Number::operator>(const Number& nr)
{
	int a, b;
	a = atoic(val, baseval);
	b = atoic(nr.val, nr.baseval);
	return a > b;
}

bool Number::operator>=(const Number& nr)
{
	int a, b;
	a = atoic(val, baseval);
	b = atoic(nr.val, nr.baseval);
	return a >= b;
}

bool Number::operator<=(const Number& nr)
{
	int a, b;
	a = atoic(val, baseval);
	b = atoic(nr.val, nr.baseval);
	return a <= b;
}

bool Number::operator==(const Number& nr)
{
	int a, b;
	a = atoic(val, baseval);
	b = atoic(nr.val, nr.baseval);
	return a == b;
}

void Number::operator--() //first digit will be removed
{
	for (int i = 0; i < count; i++)
		val[i] = val[i + 1];
	count--;
}

void Number::operator--(int a) //last digit will be removed
{
	val[count-1] = '\0';
	count--;
}

void Number::operator +=(const Number& nr)
{
	int final, a, b;
	final = (baseval > nr.baseval) ? baseval : nr.baseval;
	a = atoic(val, baseval);
	b = atoic(nr.val, nr.baseval);
	int sum;
	sum = a + b;
	delete[] val;
	val = itoac(sum, final);
	count = strlen(val);
	baseval = final;
}

Number::Number(const Number& other)
{
	baseval = other.baseval;
	count = other.count;
	val = new char[count + 1];
	strcpy(val, other.val);
}

Number::Number(Number&& other)
{
	baseval = other.baseval;
	count = other.count;
	val = new char[count + 1];
	strcpy(val, other.val);

	other.val = nullptr;
	other.count = 0;
	other.baseval = 0;
}