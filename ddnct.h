
// ddnct.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CddnctApp:
// �йش����ʵ�֣������ ddnct.cpp
//

class CddnctApp : public CWinAppEx
{
public:
	CddnctApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CddnctApp theApp;