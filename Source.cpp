#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include "NumberPerfectionLibrary.h"
using namespace std;

extern "C" int CheckValueASM(int one, int two);

HWND SendButton, TextBox, TextBoxTwo;
HWND hMainWindow, hwnd, hHeader;
HWND hwndLabel;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK windowprocessforwindow3(HWND handleforwindow3, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK windowprocessforwindow2(HWND handleforwindow2, UINT message, WPARAM wParam, LPARAM lParam);

void AddControls2(HWND hwnd);
void Createwindow2(WNDCLASSEX& wincl_2, HINSTANCE& hThisInstance, int nCmdShow);
void AddControls1(HWND);
void createwindow3(WNDCLASSEX& wincl_3, HINSTANCE& hThisInstance, int nCmdShow);
void AddControls3(HWND hwnd);

TCHAR szClassName[] = _T("LABA_2");
TCHAR szClassName2[] = _T("Perfection");
TCHAR szClassName3[] = _T("MultiplicityNumber");

char textSaved[20];
char textSavedTwo[20];
bool windowOne = false;
bool windowTwo = false;


int WINAPI WinMain(HINSTANCE hThisInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszArgument,
	int nCmdShow)
{
	setlocale(LC_ALL, "RUS");
	bool endprogram = false;

	MSG messages;
	WNDCLASSEX wincl_1;

	wincl_1.hInstance = hThisInstance;
	wincl_1.lpszClassName = szClassName;
	wincl_1.lpfnWndProc = WindowProcedure;      
	wincl_1.style = CS_DBLCLKS;                 
	wincl_1.cbSize = sizeof(WNDCLASSEX);
	wincl_1.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl_1.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl_1.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl_1.lpszMenuName = NULL;                
	wincl_1.cbClsExtra = 0;                     
	wincl_1.cbWndExtra = 0;                     
	wincl_1.hbrBackground = CreateSolidBrush(RGB(31, 31, 31));

	if (!RegisterClassEx(&wincl_1))
		return 0;
	hwnd = CreateWindowEx(
		WS_EX_TOPMOST,                   
		szClassName,         
		_T("LABA_2"),       
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
		CW_USEDEFAULT,      
		CW_USEDEFAULT,      
		600, 200,                 
		HWND_DESKTOP,        
		NULL,                
		hThisInstance,      
		NULL
	);

	ShowWindow(hwnd, nCmdShow);

	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}

	return messages.wParam;
}

void Createwindow2(WNDCLASSEX& wincl_2, HINSTANCE& hThisInstance, int nCmdShow)
{
	if (windowOne)
	{
		return;
	}
	wincl_2.hInstance = hThisInstance;
	wincl_2.lpszClassName = szClassName2;
	wincl_2.lpfnWndProc = (WNDPROC)windowprocessforwindow2;
	wincl_2.style = CS_DBLCLKS;
	wincl_2.cbSize = sizeof(WNDCLASSEX);
	wincl_2.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl_2.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl_2.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl_2.lpszMenuName = NULL;
	wincl_2.cbClsExtra = 0;
	wincl_2.cbWndExtra = 0;
	wincl_2.hbrBackground = CreateSolidBrush(RGB(31, 31, 31));
	RegisterClassEx(&wincl_2);
	//if (!RegisterClassEx(&wincl_2))
	//	return;
	HWND handleforwindow = CreateWindowEx(
		WS_EX_TOPMOST,
		szClassName2,
		_T("Perfection"),
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		330,
		320,
		HWND_DESKTOP,
		NULL,
		hThisInstance,
		NULL
	);
	windowOne = !windowOne;
	ShowWindow(handleforwindow, nCmdShow);
}

void createwindow3(WNDCLASSEX& wincl_3, HINSTANCE& hThisInstance, int nCmdShow)
{
	if (windowTwo)
	{
		return;
	}
	wincl_3.hInstance = hThisInstance;
	wincl_3.lpszClassName = szClassName3;
	wincl_3.lpfnWndProc = (WNDPROC)windowprocessforwindow3;
	wincl_3.style = CS_DBLCLKS;
	wincl_3.cbSize = sizeof(WNDCLASSEX);
	wincl_3.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl_3.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl_3.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl_3.lpszMenuName = NULL;            
	wincl_3.cbClsExtra = 0;                     
	wincl_3.cbWndExtra = 0;                      
	wincl_3.hbrBackground = CreateSolidBrush(RGB(31, 31, 31));
	RegisterClassEx(&wincl_3);
	//if (!RegisterClassEx(&wincl_3))
	//	return;
	HWND handleforwindow2 = CreateWindowEx(
		WS_EX_TOPMOST,
		szClassName3,
		_T("MultiplicityNumber"),     
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
		CW_USEDEFAULT,       
		CW_USEDEFAULT,       
		330,                
		320,                
		HWND_DESKTOP,        
		NULL,                
		hThisInstance,      
		NULL
	);
	windowTwo = !windowTwo;
	ShowWindow(handleforwindow2, nCmdShow);

}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		static HINSTANCE hInstance;
	case WM_COMMAND:
	{
		switch (wParam) {
		case 1:
		{
			WNDCLASSEX w2;
			hInstance = (HINSTANCE)::GetWindowLong(hwnd, GWL_HINSTANCE);
			Createwindow2(w2, hInstance, SW_SHOW);
			break;
		}
		case 2:
		{
			WNDCLASSEX w2;
			hInstance = (HINSTANCE)::GetWindowLong(hwnd, GWL_HINSTANCE);
			createwindow3(w2, hInstance, SW_SHOW);
			break;
		}
		}
	}
	case WM_CREATE: {
		AddControls1(hwnd);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:

		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK windowprocessforwindow2(HWND handleforwindow2, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:
	{
		switch (wParam) {
		case 1:
			GetWindowTextA(TextBox, &textSaved[0], 20);

			if (!isdigit(textSaved[0])) {
				MessageBox(handleforwindow2, "Ты ввел не число!", "-_-", MB_ICONEXCLAMATION | MB_OK);
				break;
			}

			int x = 0;
			string s(textSaved);
			sscanf(s.c_str(), "%d", &x);

			if (GetIntTmp(x) == 1)
				MessageBox(handleforwindow2, "Число совершенное!", "^_^", MB_ICONEXCLAMATION | MB_OK);
			else
				MessageBox(handleforwindow2, "Число не совершенное!", "-_-", MB_ICONEXCLAMATION | MB_OK);

			break;
		}
	}
	return 0;
	case WM_CREATE: {
		AddControls2(handleforwindow2);
		break;
	}
	case WM_DESTROY:
		windowOne = !windowOne;
		DestroyWindow(handleforwindow2);
		break;
	default:

		return DefWindowProc(handleforwindow2, msg, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK windowprocessforwindow3(HWND handleforwindow3, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:
	{
		switch (wParam) {
		case 1:
			GetWindowTextA(TextBox, &textSaved[0], 20);
			GetWindowTextA(TextBoxTwo, &textSavedTwo[0], 20);

			if (!isdigit(textSaved[0])) {
				MessageBox(handleforwindow3, "Ты ввел не число!", "-_-", MB_ICONEXCLAMATION | MB_OK);
				break;
			}
			if (!isdigit(textSavedTwo[0])) {
				MessageBox(handleforwindow3, "Ты ввел не число!", "-_-", MB_ICONEXCLAMATION | MB_OK);
				break;
			}

			int x, y = 0;
			string s(textSaved);
			string ss(textSavedTwo);

			sscanf(s.c_str(), "%d", &x);
			sscanf(ss.c_str(), "%d", &y);

			if (y == 0)
			{
				MessageBox(handleforwindow3, "На 0 делить нельзя!!", "-_-", MB_ICONEXCLAMATION | MB_OK);
				break;
			}

			if (CheckValueASM(x, y) == 0)
				MessageBox(handleforwindow3, "Число делится без остатка!", "^_^", MB_ICONEXCLAMATION | MB_OK);
			else
				MessageBox(handleforwindow3, "Хмм, при делении вышел остаток!", "-_-", MB_ICONEXCLAMATION | MB_OK);

			break;
		}
	}
	return 0;
	case WM_CREATE: {
		AddControls3(handleforwindow3);
		break;
	}
	case WM_DESTROY:
		windowTwo = !windowTwo;
		DestroyWindow(handleforwindow3);
		break;
	default:

		return DefWindowProc(handleforwindow3, msg, wParam, lParam);
	}
	return 0;
}

void AddControls1(HWND hwnd)
{
	CreateWindowW(L"Button", L" Совершенность числа", WS_VISIBLE | WS_CHILD, 100, 70, 180, 30, hwnd, (HMENU)1, NULL, NULL);
	CreateWindowW(L"Button", L" Определить кратность", WS_VISIBLE | WS_CHILD, 295, 70, 180, 30, hwnd, (HMENU)2, NULL, NULL);
}

void AddControls2(HWND hwnd)
{
	hwndLabel = CreateWindow("STATIC", "Введите число:",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		60, 100, 200, 20, hwnd, NULL, NULL, NULL);
	TextBox = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 60, 125, 200, 20, hwnd, (HMENU)NULL, NULL, NULL);
	SendButton = CreateWindow("BUTTON",
		"GO CHECK",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		60, 150, 200, 25,
		hwnd, (HMENU)1, NULL, NULL);

}

void AddControls3(HWND hwnd)
{
	hwndLabel = CreateWindow("STATIC", "Введите числа:",+

		WS_VISIBLE | WS_CHILD | WS_BORDER,
		60, 100, 200, 20, hwnd, NULL, NULL, NULL);
	TextBox = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 60, 125, 100, 20, hwnd, (HMENU)NULL, NULL, NULL);
	TextBoxTwo = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 160, 125, 100, 20, hwnd, (HMENU)NULL, NULL, NULL);
	SendButton = CreateWindow("BUTTON",
		"GO CHECK",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		60, 150, 200, 25,
		hwnd, (HMENU)1, NULL, NULL);
}