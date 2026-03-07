#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
	w = (width > 200) ? 200 : width;
	h = (height > 200) ? 200 : height;

	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int dx, dy, dist;
	//(x,y) center
	//ray^2 = (x-x0)^2 + (y-y0)^2
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
		{
			dx = i - x;
			dy = j - y;
			dist = dx * dx + dy * dy;
			if (dist > (ray*ray - ray) && dist < (ray*ray + ray) )
				SetPoint(i, j, ch);
		}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{	
	DrawCircle(x, y, ray, ch);

	int dx, dy, dist;
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
		{
			dx = i - x;
			dy = j - y;
			dist = dx * dx + dy * dy;
			if (dist <= ray*ray)
				SetPoint(i, j, ch);
		}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	//left and right on x axis
	//top and bottom on y axis
	DrawLine(left, top, right, top, ch);
	DrawLine(left, top, left, bottom, ch);
	DrawLine(left, bottom, right, bottom, ch);
	DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	DrawRect(left, top, right, bottom, ch);
	for (int i = left + 1; i < right; i++)
		for (int j = top + 1; j < bottom; j++)
			SetPoint(i, j, ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < w && y >= 0 && y < h)
		a[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1), dy = abs(y2 - y1);
	int p = 2 * dy - dx;
	int y = y1, x;


	if (x1 != x2)
	{
		for (x = x1; x < x2; x++)
		{
			SetPoint(x, y, ch);
			if (p > 0)
			{
				y++;
				p += 2 * dy - 2 * dx;
			}
			else
				p += 2 * dy;
		}
		SetPoint(x, y, ch);
	}
	else
		for (y = y1; y < y2; y++)
		{
			SetPoint(x1, y, ch);
	}


}

void Canvas::Print()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
	
}

void Canvas::Clear()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			a[i][j] = ' ';
}
