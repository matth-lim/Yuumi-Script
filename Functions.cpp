#include <iostream>
#include <windows.h>

using namespace std;


void presskey(char thekey)
{
	SHORT key;
	UINT mappedkey;
	INPUT input = { 0 };
	key = VkKeyScan(thekey);
	mappedkey = MapVirtualKey(LOBYTE(key), 0);
	input.type = INPUT_KEYBOARD;
	input.ki.dwFlags = KEYEVENTF_SCANCODE;
	input.ki.wScan = mappedkey;
	SendInput(1, &input, sizeof(input));
	Sleep(10);
	input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(input));
}

void leftmouseclick()
{
	INPUT iNPUT = { 0 };
	iNPUT.type = INPUT_MOUSE;
	iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &iNPUT, sizeof(iNPUT));
	ZeroMemory(&iNPUT, sizeof(iNPUT));
	iNPUT.type = INPUT_MOUSE;
	iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &iNPUT, sizeof(iNPUT));
}

void clickonscreen(int x, int y)
{
	SetCursorPos(x, y);
	Sleep(200);
	leftmouseclick();
}

int checkcolour(int x, int y)
{
	HDC hdc = GetDC(NULL);
	COLORREF color2 = GetPixel(hdc, x, y);
	ReleaseDC(NULL, hdc);
	return color2;
}

void rightmouseclick()
{
	INPUT iNPUT = { 0 };
	iNPUT.type = INPUT_MOUSE;
	iNPUT.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &iNPUT, sizeof(iNPUT));
	ZeroMemory(&iNPUT, sizeof(iNPUT));
	iNPUT.type = INPUT_MOUSE;
	iNPUT.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &iNPUT, sizeof(iNPUT));
}
void getcolourofcursor(HWND hWND)
{
	POINT U;
	GetCursorPos(&U);
	ScreenToClient(hWND, &U);
	HDC hdc = GetDC(NULL);
	COLORREF color = GetPixel(hdc, U.x, U.y);
	ReleaseDC(NULL, hdc);
	int red = GetRValue(color);
	int green = GetGValue(color);
	int blue = GetBValue(color);
	cout << red << ',' << green << ',' << blue << endl;
	cout << color << endl;
}