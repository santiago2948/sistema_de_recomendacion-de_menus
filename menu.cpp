#include <iostream>
#include <Windows.h>
#define B1 100
#define B2 101
#define B3 102
#define B4 103

HWND ventana2;
HWND ventana3;
HWND ventana4;


HWND hWnd;

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM wParam, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, PWSTR pwCmdArgs, int nCmdShow)
{
	const wchar_t* CLASS_NAME = L"Window Class";

	WNDCLASS wc = {};

	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.lpfnWndProc = WindowProc;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	RegisterClass(&wc);

	hWnd = CreateWindow(
		CLASS_NAME,
		L"Window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 300,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hWnd, nCmdShow);

	HWND boton1;

	boton1 = CreateWindowEx(
		0,
		L"button",
		L"Presupuesto fijo",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		10, 70, 150, 50, 
		hWnd,
		(HMENU)B1,
		hInstance, 
		NULL
	);

	HWND boton2;

	boton2 = CreateWindowEx(
		0,
		L"button",
		L"Tipo de comida",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		170, 70, 150, 50,
		hWnd,
		(HMENU)B2,
		hInstance,
		NULL
	);

	HWND boton3;

	boton3 = CreateWindowEx(
		0,
		L"button",
		L"Si incluye bebida",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		330, 70, 150, 50,
		hWnd,
		(HMENU)B3,
		hInstance,
		NULL
	);

	HWND boton4;
	//ventana 4 (incluye bebida)
	boton4 = CreateWindowEx(
		0,
		L"button",
		L"Si",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		10, 70, 170, 50,
		ventana4,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);

	HWND boton5;
	//ventana 4 (incluye bebida)
	boton5 = CreateWindowEx(
		0,
		L"button",
		L"No",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		330, 70, 170, 50,
		ventana4,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);

	HWND boton6;
	//ventana 3 (tipo de comida)
	boton6 = CreateWindowEx(
		0,
		L"button",
		L"Colombiana",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		10, 70, 150, 50,
		ventana3,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);

	HWND boton7;
	//ventana 3 (tipo de comida)
	boton7 = CreateWindowEx(
		0,
		L"button",
		L"Mexicana",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		170, 70, 150, 50,
		ventana3,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);

	HWND boton8;
	//ventana 3 (tipo de comida)
	boton8 = CreateWindowEx(
		0,
		L"button",
		L"China",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		330, 70, 150, 50,
		ventana3,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);

	HWND boton9;
	//ventana 3 (tipo de comida)
	boton9 = CreateWindowEx(
		0,
		L"button",
		L"India",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		50, 150, 150, 50,
		ventana3,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);

	HWND boton10;
	//ventana 3 (tipo de comida)
	boton10 = CreateWindowEx(
		0,
		L"button",
		L"Italiana",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		250, 150, 150, 50,
		ventana3,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);
	HWND boton11;
	boton11 = CreateWindowEx(
		0,
		L"button",
		L"Volver al Menú principal",
		WS_VISIBLE | WS_CHILD | 0x00000001,
		250, 150, 150, 50,
		NULL,
		(HMENU)B4,
		GetModuleHandle(NULL),
		NULL
	);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
void OnButtonClick(HWND hWnd, WPARAM wParam) {
	switch (LOWORD(wParam)) {
	case B1:
		// Si se presiona el botón 1 (B1), abre la ventana 2

		ventana2 = CreateWindow(
			L"STATIC",
			L"Presupuesto fijo",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			400, 300,
			HWND_DESKTOP,
			NULL,
			GetModuleHandle(NULL),
			NULL
		);


		ShowWindow(ventana2, SW_SHOWNORMAL);
		break;
		
	case B2:

		ventana3 = CreateWindow(
			L"STATIC",
			L"Tipo de comida",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			400, 300,
			HWND_DESKTOP,
			NULL,
			GetModuleHandle(NULL),
			NULL
		);

		ShowWindow(ventana3, SW_SHOWNORMAL);
		break;

	case B3:

		ventana4 = CreateWindow(
			L"STATIC",
			L"Incluye bebida",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			400, 300,
			HWND_DESKTOP,
			NULL,
			GetModuleHandle(NULL),
			NULL
		);
		ShowWindow(ventana4, SW_SHOWNORMAL);
		break;
	case B4:
		break;
	}
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc;

		hdc = BeginPaint(hWnd, &ps);

		TextOut(hdc, 160, 10, L"Recomendacion de Menus", wcslen(L"Recomendacion de Menus"));
		TextOut(hdc, 180, 40, L"Escoge una opción", wcslen(L"Escoge una opción"));

	
		EndPaint(hWnd, &ps);
		break;
	}
		
	case WM_COMMAND:
		OnButtonClick(hWnd, wParam);
		break;


	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}