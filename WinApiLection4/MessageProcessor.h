#pragma once
#include <windows.h>
#include <windowsx.h>
#include"Header.h"

class MessageProcessor
{
	MSG message;
	Window *mainWin;
public:
	static MessageProcessor *instance;
	MessageProcessor(Window *mainWin);
	~MessageProcessor();

	void OnClose(HWND hwnd);
	BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void OnCommandAction(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);

	void MessageHandler();
	static BOOL CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

};

