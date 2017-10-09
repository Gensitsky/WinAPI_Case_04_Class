#pragma once
#include "resource.h"
#include <windows.h>

class Window
{
	HINSTANCE mainInst;
	int show;
	

public:
	static BOOL CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	HWND mainWinHWND,
		btnClearHWND,
		btnAddHWND,
		btnDeleteHWND,
		editNameHWND,
		editAuthorHWND,
		comboBoxHWND,
		listBoxHWND,
		datePickerHWND,
		filterComboBoxHWND;

	HWND radioButtonsHWND[3],
		checkBoxHWND[3];

	Window(HINSTANCE hInst, int nCmdShow);
	~Window();

	void ShowMainWindow();
	void SetMainWindowHWND(HWND target);
	void InitWindow(HWND hwnd, HWND hwndFocus, LPARAM lParam);

	void SetStatics(HWND hWnd);
	void SetButtons(HWND hWnd);
	void SetRadioButtons(HWND hWnd);
	void SetCheckBoxes(HWND hWnd);
	void SetInputs(HWND hWnd);
	void SetComboBox(HWND hWnd);
	void SetListBox(HWND hWnd);
	void SetCalendar(HWND hWnd);
	void SetFilter(HWND hWnd);
	void CreateDetailWindow();
};

