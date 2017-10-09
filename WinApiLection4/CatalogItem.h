#pragma once
#include<tchar.h>
class CatalogItem
{
public:
	TCHAR name[100];
	TCHAR author[100];
	TCHAR date[100];

	CatalogItem();
	~CatalogItem();
};

