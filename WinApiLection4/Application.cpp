#pragma once 
#include "Header.h"

int ExecuteProgram(HINSTANCE hInst, int nCmdShow)
{
	Window *_mainWindow = new Window(hInst, nCmdShow);
	MessageProcessor _messageProcessor(_mainWindow);
	_mainWindow->SetMainWindowHWND(CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, _messageProcessor.WindowProc));
	_mainWindow->ShowMainWindow();
	_messageProcessor.MessageHandler();
	return 0;
}