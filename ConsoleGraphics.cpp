#define _CRT_SECURE_NO_DEPRECATE
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <list>
#define print cout<<
using namespace std;

void window1(int height, int width, int x_pos, int y_pos)//parameters uses to set window size and position
{
	HWND wh = GetConsoleWindow();
	MoveWindow(wh, x_pos, y_pos, width, height, TRUE);
	HANDLE hInput;
	DWORD prev_mode;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ENABLE_EXTENDED_FLAGS);
	ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);//hide scrollbar becouse scrolling broke picture
	HDC hdc = GetDC(GetConsoleWindow());
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;//hide cursor
	SetConsoleCursorInfo(consoleHandle, &info);
}

void window()
{
	window1(440, 800, 300, 200);//set window size
}

unsigned long color(string name)//return color from it's string
{
	if (name == "red")
		return RGB(250, 0, 0);
	if (name == "green")
		return RGB(0, 250, 0);
	if (name == "blue")
		return RGB(0, 0, 250);
	if (name == "pink")
		return RGB(250, 100, 100);
	if (name == "cyan")
		return RGB(0, 250, 250);
	if (name == "violet")
		return RGB(250, 0, 250);
	if (name == "yellow")
		return RGB(250, 250, 0);
	if (name == "azure")
		return RGB(100, 100, 250);
	if (name == "orange")
		return RGB(250, 150, 0);
	if (name == "maroon")
		return RGB(150, 0, 0);
	if (name == "lime")
		return RGB(100, 250, 100);
}

int fun(float x1, float x2, float y1, float y2, float x)//calculate geometric function of line
{
	return round(y1 + ((y2-y1)/(x2-x1)*(x-x1)));
}

void line(int x1, int y1, int x2, int y2, int masshtab, string colour)
{
	y1 = 400 - masshtab * y1-20;//we get start and end points of line, based on a scale
	y2 = 400 - masshtab * y2-20;
	x1 = masshtab * x1;
	x2 = masshtab * x2;
	HDC hdc = GetDC(GetConsoleWindow());
	for (int i = x1; i < x2; ++i)//draw each ixel thats on line
	{
		int f = fun(x1, x2, y1, y2, i);
		SetPixel(hdc, i, f, color(colour));
		SetPixel(hdc, i, f-1, color(colour));
	}
}

void plot(int height, int width, int *x, int *y, string colour)//to draw solid plot give function array of points
{
	line(-10, -10, 100, 0, 10, "cyan");
	int masshtab = 400/height;
	for (int i = 0; i < sizeof(x); i++)
		line(x[i],y[i],x[i+1],y[i+1], masshtab, colour);
}


void main()//example to use that all
{
	int i;
	int x[5] = { 1, 5, 10, 15, 20 };
	int y1[5] = { 1, 7, 3, 5, 11 };
	int y2[5] = { 4, 3, 1, 8, 12 };
	int y3[5] = { 2, 2, 4, 3, 10 };
	int y4[5] = { 0, 4, 9, 5, 8 };

	int *X = new int[5];
	int *Y1 = new int[5];
	int *Y2 = new int[5];
	int *Y3 = new int[5];
	int *Y4 = new int[5];
	for (int j = 0; j < 5; j++)
	{
		X[j] = x[j];
		Y1[j] = y1[j];
		Y2[j] = y2[j];
		Y3[j] = y3[j];
		Y4[j] = y4[j];
	}

	window();

	for (int j = 12; j > 1; j--)
	{
		print "\n\n";
		print j;
	}
	print endl;
	for (int j = 5; j <= 20 ; j+=5)
	{
		print "                  ";
		print j;
	}

	plot(12, 20, x, y1, "pink");

	plot(12, 20, x, y2, "lime");

	plot(12, 20, x, y3, "violet");

	plot(12, 20, x, y4, "orange");

	cin >> i;
}
