#include <iostream>
#include "Math.h"
int main()
{
	printf("Suma cu doua int-uri: %d + %d = %d\n", 4, 3, Math::Add(4, 3));
	printf("Suma cu trei int-uri %d + %d + %d = %d\n",4, 3, 3, Math::Add(4, 3, 3));
	printf("Suma cu doua double-uri: %.2f + %.2f = %.2f\n", 4.2, 3.2, Math::Add(4.2, 3.2));
	printf("Suma cu trei double-uri:  %.2f + %.2f + %.2f = %.2f\n", 4.2, 3.2, 3.2, Math::Add(4.2, 3.2,3.2));
	printf("Inmultire cu doua int-uri %d * %d = %d\n", 4, 3, Math::Mul (4, 3));
	printf("Inmultire cu trei inturi: %d * %d * %d = %d\n", 4, 3, 3, Math::Mul(4, 3, 3));
	printf("Inmultire cu doua double-uri: %.2f * %.2f = %.2f\n", 4.2, 3.2, Math::Mul(4.2, 3.2));
	printf("Inmultire cu trei double-uri: %.2f * %.2f * %.2f  = %.2f\n", 4.2, 3.2, 3.2, Math::Mul(4.2, 3.2, 3.2));
	printf("Adunare cu variadic: %d\n", Math::Add(5, 1, 2, 3, 4, 5));
	printf("Adunare siruri: %s + %s = %s\n", "ab", "cd", Math::Add("ab", "cd"));
}