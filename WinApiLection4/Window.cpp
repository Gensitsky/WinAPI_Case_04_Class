#include "Window.h"


Window::Window(HINSTANCE hInst, int nCmdShow)
{
	mainInst = hInst;
	show = nCmdShow;
}


Window::~Window()
{

}

void Window::ShowMainWindow()
{
	ShowWindow(mainWinHWND, show);
}

void Window::SetMainWindowHWND(HWND target)
{
	mainWinHWND = target;
}


void Window::InitWindow(HWND hWnd, HWND hwndFocus, LPARAM lParam)
{
	SetStatics(hWnd);
	SetButtons(hWnd);
	SetRadioButtons(hWnd);
	SetCheckBoxes(hWnd);
	SetInputs(hWnd);
	SetComboBox(hWnd);
	SetListBox(hWnd);
	SetCalendar(hWnd);
	SetFilter(hWnd);
}


void Window::SetStatics(HWND hWnd)
{
	SetWindowText(hWnd, L"Catalog");
	CreateWindowEx(0, L"BUTTON", L"Collection Data", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 230, 10, 270, 260, hWnd, 0, GetModuleHandle(0), 0);
	CreateWindowEx(0, L"STATIC", L"Filter", WS_CHILD | WS_VISIBLE, 10, 10, 45, 15, hWnd, 0, mainInst, 0);
	CreateWindowEx(0, L"STATIC", L"Type", WS_CHILD | WS_VISIBLE, 270, 40, 45, 15, hWnd, 0, mainInst, 0);
	CreateWindowEx(0, L"STATIC", L"Name", WS_CHILD | WS_VISIBLE | SS_CENTER, 270, 80, 45, 15, hWnd, 0, mainInst, 0);
	CreateWindowEx(0, L"STATIC", L"Author", WS_CHILD | WS_VISIBLE | SS_CENTER, 270, 120, 45, 15, hWnd, 0, mainInst, 0);
	CreateWindowEx(0, L"STATIC", L"Date", WS_CHILD | WS_VISIBLE | SS_CENTER, 270, 160, 45, 15, hWnd, 0, mainInst, 0);
}

void Window::SetButtons(HWND hWnd)
{
	btnClearHWND = CreateWindowEx(0, L"BUTTON", L"Clear", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 230, 280, 80, 30, hWnd, NULL, mainInst, 0);
	btnAddHWND = CreateWindowEx(0, L"BUTTON", L"Add", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 325, 280, 80, 30, hWnd, NULL, mainInst, 0);
	btnDeleteHWND = CreateWindowEx(0, L"BUTTON", L"Delete", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 420, 280, 80, 30, hWnd, NULL, mainInst, 0);
}
void Window::SetRadioButtons(HWND hWnd)
{
	TCHAR tmpStr[100];
	for (int i = 0; i < 3; i++)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		wsprintf(tmpStr, TEXT("Radio %i"), i);
		radioButtonsHWND[i] = CreateWindowEx(0, L"BUTTON", tmpStr, WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 400, 190 + 1 * (i * 25), 70, 20, hWnd, NULL, mainInst, 0);
	}
	SetWindowLong(radioButtonsHWND[0], 0, WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP);

	//BOOL CheckDlgButton(
	//	HWND hDlg, //дескриптор диалога, содержащего кнопку
	//	//(флажок)
	//	int nIDButton, //идентификатор элемента управлени€   //BM_GETCHECK,
	//	//(флажка)
	//	UINT uCheck //состо€ние флажка Ч одно из
	//	//вышеперечисленных значений
	//	);
}
void Window::SetCheckBoxes(HWND hWnd)
{
	TCHAR tmpStr[100];
	for (int i = 0; i < 3; i++)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		wsprintf(tmpStr, TEXT("CheckBox %i"), i);
		checkBoxHWND[i] = CreateWindowEx(0, L"BUTTON", tmpStr, WS_VISIBLE | WS_CHILD | BS_CHECKBOX, 270, 190 + 1 * (i * 25), 100, 20, hWnd, NULL, mainInst, 0);
	}
	//BOOL CheckDlgButton(
	//	HWND hDlg, //дескриптор диалога, содержащего кнопку
	//	//(флажок)
	//	int nIDButton, //идентификатор элемента управлени€
	//	//(флажка)
	//	UINT uCheck //состо€ние флажка Ч одно из
	//	//вышеперечисленных значений
	//	);
}

void Window::SetInputs(HWND hWnd)
{
	editNameHWND = CreateWindowEx(0, L"EDIT", L"Add", WS_VISIBLE | WS_CHILD | WS_BORDER, 370, 80, 100, 20, hWnd, NULL, mainInst, 0);
	editAuthorHWND = CreateWindowEx(0, L"EDIT", L"Author", WS_VISIBLE | WS_CHILD | WS_BORDER, 370, 120, 100, 20, hWnd, NULL, mainInst, 0);
}

void Window::SetComboBox(HWND hWnd)
{
	TCHAR tmpStr[100];
	comboBoxHWND = CreateWindowEx(0, L"COMBOBOX", L"Add", WS_VISIBLE | WS_CHILD | WS_BORDER | CBS_DROPDOWN, 370, 40, 100, 200, hWnd, NULL, mainInst, 0);
	for (int i = 0; i < 5; i++)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		wsprintf(tmpStr, TEXT("Option %i"), i);
		SendMessage(comboBoxHWND, CB_ADDSTRING, 0, (LPARAM)tmpStr);
	}
	SendMessage(comboBoxHWND, CB_SETCURSEL, 0, 0);

	//CB_GETLBTEXT CB_GETCURSEL  CBN_SELCHANGE


}
void Window::SetListBox(HWND hWnd)
{
	listBoxHWND = CreateWindowEx(0, L"LISTBOX", L"List", WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | ES_AUTOVSCROLL, 10, 35, 210, 280, hWnd, NULL, mainInst, 0);
	
	TCHAR tmpStr[100];
	wsprintf(tmpStr, TEXT("Test"));
	for (int i = 0; i < 10; i++)
	{
		SendMessage(listBoxHWND, LB_INSERTSTRING, 0, (LPARAM)tmpStr);
	}

}
void Window::SetCalendar(HWND hWnd)
{
	datePickerHWND = CreateWindowEx(0, L"SysDateTimePick32", 0, WS_BORDER | WS_CHILD | WS_VISIBLE,320, 152, 160, 25, hWnd, 0, mainInst, 0);
}
void Window::SetFilter(HWND hWnd)
{
	TCHAR tmpStr[100];
	filterComboBoxHWND = CreateWindowEx(0, L"COMBOBOX", L"Filter", WS_VISIBLE | WS_CHILD | WS_BORDER | CBS_DROPDOWN, 60, 6, 160, 200, hWnd, NULL, mainInst, 0);
	for (int i = 0; i < 5; i++)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		wsprintf(tmpStr, TEXT("Filter %i"), i);
		SendMessage(filterComboBoxHWND, CB_ADDSTRING, 0, (LPARAM)tmpStr);
	}
	SendMessage(filterComboBoxHWND, CB_SETCURSEL, 0, 0);
}

void Window::CreateDetailWindow()
{
	//создание окна при клике на add
	HWND xxx = CreateDialog(mainInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, WindowProc);
	ShowWindow(xxx, show);

}

BOOL CALLBACK  Window::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int index = 0;
	switch (message)
	{
	case WM_CLOSE:

		break;
		// обработчик нового окна
		return TRUE;
	}
	return FALSE;
}

