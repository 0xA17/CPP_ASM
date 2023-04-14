#include "pch.h"
#include <utility>
#include <tchar.h>
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include "..//NumberPerfection/NumberPerfectionLibrary.h"
using namespace std;

TCHAR szClassName2[] = _T("Perfection");

bool windowOne = false;

void AddControls2(HWND hwnd);
void Createwindow2(WNDCLASSEX& wincl_2, HINSTANCE& hThisInstance, int nCmdShow);
LRESULT CALLBACK windowprocessforwindow2(HWND handleforwindow2, UINT message, WPARAM wParam, LPARAM lParam);


