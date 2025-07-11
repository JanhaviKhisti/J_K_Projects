// Header Files
# include<windows.h>
# include"Window.h"
#define ID_TIMER 1 

//global fuctions declerations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//global variable declerations

//Entry Point Fuction
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//local variable declerations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	static TCHAR szAppName[] = TEXT("Bounce");

	//code
	//WNDCLASSEX initialisation
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_HAND);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	//registration of WNDCLASSEX
	RegisterClassEx(&wndclass);
	// if(!RegisterClassEx(&wndclass))
	// {
	// 	MessageBox (NULL, TEXT("This program requires Windows 10!"), szAppName, MB_ICONERROR);
	// 	return 0;
	// }

	//creating the window
	hwnd = CreateWindow(szAppName, TEXT("J_K Bouncing Ball"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//show window
	ShowWindow(hwnd, iCmdShow);

	//update window
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return ((int)msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT imsg, WPARAM wParam, LPARAM lParam)
{
	// local variable declerations 
	static HBITMAP hBitmap;
	static int cxClient, cyClient, xCenter, yCenter, cxTotal, cyTotal, cxRadius, cyRadius, cxMove, cyMove, xPixel, yPixel;
	HBRUSH hBrush;
	HDC hdc, hdcMem;
	int iScale;

	//code
	switch (imsg)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);
		xPixel = GetDeviceCaps(hdc, ASPECTX);
		yPixel = GetDeviceCaps(hdc, ASPECTY);
		ReleaseDC(hwnd, hdc);

		SetTimer(hwnd, ID_TIMER, 50, NULL);
		return 0;

	case WM_SIZE:
		xCenter = (cxClient = LOWORD(lParam)) / 2;
		yCenter = (cyClient = HIWORD(lParam)) / 2;

		iScale = min(cxClient * xPixel, cyClient * yPixel) / 16;

		cxRadius = iScale / xPixel;
		cyRadius = iScale / yPixel;

		cxMove = max(1, cxRadius / 2);
		cyMove = max(1, cyRadius / 2);

		cxTotal = 2 * (cxRadius + cxMove);
		cyTotal = 2 * (cyRadius + cyMove);

		if(hBitmap)
		{
			DeleteObject(hBitmap);
		}

		hdc = GetDC(hwnd);
		hdcMem = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, cxTotal, cyTotal);
		ReleaseDC(hwnd, hdc);

		SelectObject(hdcMem, hBitmap);
		Rectangle(hdcMem, -1, -1, cxTotal + 1, cyTotal + 1);

		hBrush = CreateHatchBrush(HS_DIAGCROSS, 0L);
		SelectObject(hdcMem, hBrush);
		SetBkColor(hdcMem, RGB(255, 0, 0));
		Ellipse(hdcMem, cxMove, cyMove, cxTotal - cxMove, cyTotal - cyMove);
		DeleteDC(hdcMem);
		DeleteObject(hBrush);
		return 0;

	case WM_TIMER:
		if(!hBitmap)
			break;
		
		hdc = GetDC(hwnd);
		hdcMem = CreateCompatibleDC(hdc);
		SelectObject(hdcMem, hBitmap);

		BitBlt(hdc, xCenter - cxTotal / 2, yCenter - cyTotal / 2, cxTotal, cyTotal, hdcMem, 0, 0, SRCCOPY);

		ReleaseDC(hwnd, hdc);
		DeleteDC(hdcMem);

		xCenter += cxMove;
		yCenter += cyMove;

		if((xCenter + cxRadius >= cxClient) || (xCenter - cxRadius <= 0))
		{
			cxMove = -cxMove;
		}

		if((yCenter + cyRadius >= cyClient) || (yCenter - cyRadius <= 0))
		{
			cyMove = -cyMove;
		}
		return 0;

	case WM_DESTROY:
		if(hBitmap)
		{
			DeleteObject(hBitmap);
		}
		KillTimer(hwnd, ID_TIMER);
		PostQuitMessage(0);
		return 0; 

	default:
		break;
	}

	return(DefWindowProc(hwnd, imsg, wParam, lParam));

}

