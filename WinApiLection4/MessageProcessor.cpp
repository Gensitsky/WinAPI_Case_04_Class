#include "MessageProcessor.h"

MessageProcessor* MessageProcessor::instance = nullptr; // память выделяется на этапе запуска приложения до первого использования

MessageProcessor::MessageProcessor(Window *win)
{
	instance = this;
	mainWin = win;
}


MessageProcessor::~MessageProcessor()
{
}

void MessageProcessor::MessageHandler()
{
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}


BOOL CALLBACK  MessageProcessor::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, instance->OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, instance->OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, instance->OnCommandAction);
	default:
		return FALSE;
	}
	return FALSE;
}

void MessageProcessor::OnClose(HWND hWnd)
{
	DestroyWindow(hWnd);
	PostQuitMessage(0);
}
BOOL MessageProcessor::OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	mainWin->InitWindow(hwnd, hwndFocus, lParam);

	return TRUE;
}

void MessageProcessor::OnCommandAction(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	if (hwndCtl == mainWin->btnClearHWND)
	{
		SetWindowText(mainWin->mainWinHWND, L"Clear222222");

	}
	else if (hwndCtl == mainWin->btnAddHWND)
	{
		SetWindowText(mainWin->mainWinHWND, L"Add22222");
		mainWin->CreateDetailWindow();

		CatalogItem item;

		GetWindowText(mainWin->editNameHWND, item.name, 100);
		GetWindowText(mainWin->editAuthorHWND, item.author, 100);
		auto res = IsDlgButtonChecked(mainWin->mainWinHWND, GetDlgCtrlID(mainWin->radioButtonsHWND[0]));
		
		//UINT IsDlgButtonChecked(
		//	HWND hDlg, //дескриптор диалога, содержащего кнопку
		//	//(флажок)
		//	int nIDButton //идентификатор элемента управления
		//	//(флажка)


		//Сcombobox
		//int nIndex = ::SendMessage(hCombo, CB_GETCURSEL, 0, 0);
		//TCHAR F[4];
		//SendMessage(hCombo, CB_GETLBTEXT, (WPARAM)nIndx, (LPARAM)F);


		// get sel combobox
		//  If there is no current selection, set one. 
		//if (SendMessage(hwndCombo, CB_GETCURSEL, 0, 0)
		//	== CB_ERR)
		//{
		//	if (SendMessage(hwndCombo, WM_GETTEXT,
		//		sizeof(achTemp), (LPARAM)achTemp) == 0)
		//		break;      //  Empty selection field 
		//	dwIndex = SendMessage(hwndCombo,
		//		CB_FINDSTRINGEXACT, (WPARAM)(-1),
		//		(LPARAM)achTemp);
		//}
	}

}

