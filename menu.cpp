#include <iostream>
#include <Windows.h>
#include "controlador.h"
MenuDatasource datos= MenuDatasource();
vector<Comida> menues = datos.getMenus();
Controller controlador = Controller(menues);

#define B1 100 //presupuesto fijo
#define B2 101 //tipo de comida
#define B3 102 //si incluye bebida
#define B4 103 //colombiana
#define B5 104 //mexicana
#define B6 105 //china
#define B7 106 //india
#define B8 107//italiana
#define B9 108 //Si
#define B10 109 //No


HWND ventana2;
HWND ventana3;
HWND ventana4;
HWND ventana5;
HWND boton1; //presupuesto fijo
HWND boton2; //tipo de comida
HWND boton3; //si incluye bebida
HWND boton4;
HWND boton5;
HWND boton6;
HWND boton7;
HWND boton8;
HWND boton9;
HWND boton10;
HWND ListBox1;



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
	}
}

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
	UpdateWindow(hWnd);

	MSG msg;
	while (TRUE == GetMessage(&msg,0, 0, 0))
	{
		TranslateMessage(&msg);	
		DispatchMessage(&msg);
	}
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{	
	vector<vector<string>> values = controlador.getReco();

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
	
	case WM_CREATE:
		boton1 = CreateWindowEx(
			0,
			L"button",
			L"Presupuesto fijo",
			WS_VISIBLE | WS_CHILD | 0x00000001,
			10, 70, 150, 50,
			hWnd,
			(HMENU)B1,
			GetModuleHandle(NULL),
			NULL
		);

		boton2 = CreateWindowEx(
			0,
			L"button",
			L"Tipo de comida",
			WS_VISIBLE | WS_CHILD | 0x00000001,
			170, 70, 150, 50,
			hWnd,
			(HMENU)B2,
			GetModuleHandle(NULL),
			NULL
		);

		boton3 = CreateWindowEx(
			0,
			L"button",
			L"Si incluye bebida",
			WS_VISIBLE | WS_CHILD | 0x00000001,
			330, 70, 150, 50,
			hWnd,
			(HMENU)B3,
			GetModuleHandle(NULL),
			NULL
		);
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
		//ventana 4 (incluye bebida)
		boton4 = CreateWindowEx(
			0,
			L"button",
			L"Si",
			BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
			10, 70, 170, 50,
			ventana4,
			(HMENU)B9,
			GetModuleHandle(NULL),
			NULL
		);
		//ventana 4 (incluye bebida)
		boton5 = CreateWindowEx(
			0,
			L"button",
			L"No",
			BS_PUSHBUTTON |WS_CHILD| WS_VISIBLE,
			200, 70, 170, 50,
			ventana4,
			(HMENU)B10,
			GetModuleHandle(NULL),
			NULL
		);
		ventana3 = CreateWindow(
			L"STATIC",
			L"Tipo de comida",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			500, 300,
			HWND_DESKTOP,
			NULL,
			GetModuleHandle(NULL),
			&hWnd
		);
		//ventana 3 (tipo de comida)
		boton6 = CreateWindowEx(
			0,
			L"BUTTON",
			L"Colombiana",
			BS_PUSHBUTTON |WS_VISIBLE | WS_CHILD,
			10, 70, 150, 50,
			ventana3,
			(HMENU)B4,
			GetModuleHandle(NULL),
			NULL
		);
		//ventana 3 (tipo de comida)
		boton7 = CreateWindowEx(
			0,
			L"button",
			L"Mexicana",
			BS_PUSHBUTTON |WS_VISIBLE| WS_CHILD,
			170, 70, 150, 50,
			ventana3,
			(HMENU)B5,
			GetModuleHandle(NULL),
			NULL
		);
		//ventana 3 (tipo de comida)
		boton8 = CreateWindowEx(
			0,
			L"button",
			L"China",
			BS_PUSHBUTTON  |WS_VISIBLE| WS_CHILD,
			330, 70, 150, 50,
			ventana3,
			(HMENU)B6,
			GetModuleHandle(NULL),
			NULL
		);
		//ventana 3 (tipo de comida)
		boton9 = CreateWindowEx(
			0,
			L"button",
			L"India",
			BS_PUSHBUTTON  | WS_VISIBLE |WS_CHILD,
			80, 150, 150, 50,
			ventana3,
			(HMENU)B7,
			GetModuleHandle(NULL),
			NULL
		);
		//ventana 3 (tipo de comida)
		boton10 = CreateWindowEx(
			0,
			L"BUTTON",
			L"Italiana",
			BS_PUSHBUTTON |WS_CHILD | WS_VISIBLE,
			250, 150, 150, 50,
			ventana3,
			(HMENU)B8,
			GetModuleHandle(NULL),
			NULL
		);
		ventana5 = CreateWindow(
			L"STATIC",
			L"Respuesta tipo_c",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			500, 300,
			HWND_DESKTOP,
			NULL,
			GetModuleHandle(NULL),
			&hWnd
		);
		//respuesta tipo de comida
		ListBox1 = CreateWindowEx(
			0,
			L"LISTBOX",
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			20, 20, 200, 150, 
			ventana2,
			NULL,
			GetModuleHandle(NULL),
			&hWnd
		);
		break;

	case WM_COMMAND:
		OnButtonClick(hWnd, wParam);
		if (LOWORD(wParam) == B2) {
			ShowWindow(ventana3, SW_SHOW);
			break;
		}
		else if (LOWORD(wParam) == B3) {
			ShowWindow(ventana4, SW_SHOW);
			break;
		}
		else if (LOWORD(wParam) == B4) {
			MessageBox(nullptr, L"Presionaste el botón", L"Prueba", MB_OK);
			controlador.setRecos("Colombiana");
			controlador.getReco();
			for (size_t i = 0; i < values.size(); i++) {
				string nombre = values[i][0];
				SendMessage(ListBox1, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>(nombre.c_str()));
			}
			ShowWindow(ventana5, SW_SHOW);
			break;
		}
		else if (LOWORD(wParam) == B9) {
			MessageBox(nullptr, L"Presionaste el botón", L"Prueba", MB_OK);
			break;
		}
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		DestroyWindow(ventana3);
		DestroyWindow(ventana4);
		DestroyWindow(ventana5);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}