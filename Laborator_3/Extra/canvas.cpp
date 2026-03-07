#include "canvas.h"
// contructor will call the clear method
Canvas::Canvas(int lines, int columns)
{
	row = lines;
	col = columns;
	clear();
}

// set the character at the position x and y to value
void Canvas::set_pixel(int x, int y, char value)
{
	if (x >= 0 && x < row && y>=0 && y < col)
		a[x][y] = value;
}

// tuples of x, y, value
void Canvas::set_pixels(int count, ...)
{
	int x, y, val;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		x = va_arg(args, int);
		y = va_arg(args, int);
		val = va_arg(args, int);
		set_pixel(x, y, (char)val);
	}
	va_end(args);
}

void Canvas::clear()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = ' ';
}

void Canvas::print() const
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
}