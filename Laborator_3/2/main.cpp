#include "Canvas.h"
int main()
{
	Canvas can(80,80);
	can.FillRect(35, 35, 65, 65, '.');
	can.DrawRect(35, 35, 65, 65, '=');

	can.FillCircle(50, 50, 10, '_');
	can.DrawCircle(50, 50, 10, '#');
	
	can.FillCircle(45, 48, 2, '/');
	can.DrawCircle(45, 48, 2, '#');
	can.FillCircle(55, 48, 2, '/');
	can.DrawCircle(55, 48, 2, '#');

	can.DrawLine(46, 53, 54, 56 , 'o');
	can.DrawLine(47, 48, 53, 48, 'o');

	can.Print();	

}