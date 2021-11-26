#include <iostream>
#include <windows.h>
#include "Functions.h"

using namespace std;

int main()
{
	while (true)
	{
		// get id of League of Legends window
		LPCWSTR window_title = L"League of Legends";
		HWND hWND = FindWindow(NULL, window_title);
		// get id of League of Legends (TM) Client window
		LPCWSTR window_title1 = L"League of Legends (TM) Client";
		HWND hWNd = FindWindow(NULL, window_title1);
		// run the yuumi bot with F1
		if (GetAsyncKeyState(VK_F1))
		{
			// click play button
			clickonscreen(439, 194);
			Sleep(1000);
			// click co-op vs ai button
			clickonscreen(463, 256);
			Sleep(1000);
			// click intermediate button
			clickonscreen(775, 715);
			Sleep(1000);
			bool run = true;
			while (run)
			{

				// click confirm button
				clickonscreen(837, 843);
				Sleep(2000);
				// click find match button
				leftmouseclick();
				Sleep(1000);
				while (true)
				{
					// check colour of the party button
					int color1 = checkcolour(1319, 265);
					// check colour of the in-game loading screen bar
					int color2 = checkcolour(957, 1070);
					// in-champ select
					if (color1 == 1051910)
					{
						Sleep(500);
						// click on search champion
						clickonscreen(1095, 262);
						presskey('y');
						Sleep(100);
						presskey('u');
						Sleep(100);
						presskey('u');
						Sleep(100);
						presskey('m');
						Sleep(100);
						presskey('i');
						Sleep(100);
						// click on yuumi icon
						clickonscreen(701, 317);
						Sleep(200);
						// click on lock-in
						clickonscreen(957, 763);
						continue;
					}
					// queue pop
					else if (color1 == 2105634)
					{
						// click on accept button
						clickonscreen(953, 710);
						continue;
					}
					// in-loading screen
					else if (color2 == 3092738 || color2 == 7765766)
					{
						break;
					}
					// in-queue
					else
						continue;
				}
				SetFocus(hWNd);
				// check in-game or not
				while (true)
				{
					int color3 = checkcolour(871, 1010);
					if (color3 == 8063000)
					{
						break;
					}
				}
				Sleep(200);
				// level up yuumi e
				presskey('l');
				Sleep(200);
				// lock cam
				presskey('m');
				Sleep(200);
				while (true)
				{
					// check color of yuumi w
					int color4 = checkcolour(871, 1010);
					// check color of honor screen
					int color5 = checkcolour(960, 810);
					if (color4 == 8063000)
					{
						SetCursorPos(1887, 758);
						Sleep(200);
						presskey('w');
						Sleep(200);
						presskey('e');

					}
					if (color5 == 7112845)
					{
						break;
					}
					presskey('e');
					Sleep(2000);
				}
				Sleep(2000);
				// click honor screen arrow button
				clickonscreen(960, 810);
				Sleep(2000);
			}
		}
		if (GetAsyncKeyState(VK_F2))
		{
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(hWNd, &p);
			cout << "x pos: " << p.x << " y pos: " << p.y << endl;
			Sleep(1000);
		}
		if (GetAsyncKeyState(VK_F3))
		{

		}
		if (GetAsyncKeyState(VK_F4))
		{

		}
		if (GetAsyncKeyState(VK_F5))
		{

		}
		if (GetAsyncKeyState(VK_F6))
		{

		}
		if (GetAsyncKeyState(VK_F7))
		{

		}
		if (GetAsyncKeyState(VK_F8))
		{

		}
		if (GetAsyncKeyState(VK_F10))
		{

		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			return 0;
		}

	}
}
