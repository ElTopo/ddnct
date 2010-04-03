
// ddnct.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "ddnct.h"
#include "ddnctDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CddnctApp

BEGIN_MESSAGE_MAP(CddnctApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CddnctApp 构造

CddnctApp::CddnctApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CddnctApp 对象

CddnctApp theApp;


// CddnctApp 初始化

BOOL CddnctApp::InitInstance()
{
	CWinAppEx::InitInstance();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	// locale
	const int STR_SZ = 1024;
	TCHAR szBuf[STR_SZ] = { 0 };
	TCHAR szLocale[STR_SZ] = { 0 };

	::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SENGLANGUAGE, szBuf, STR_SZ);
	::_tcscpy_s(szLocale, szBuf);
	::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SENGCOUNTRY, szBuf, STR_SZ);
	if (::_tcsclen(szBuf) != 0){
		::_tcscat_s(szLocale, _T("_"));
		::_tcscat_s(szLocale, szBuf);
	}
	::GetLocaleInfo(LOCALE_SYSTEM_DEFAULT, LOCALE_IDEFAULTANSICODEPAGE, szBuf, STR_SZ);
	if (::_tcsclen(szBuf) != 0){
		::_tcscat_s(szLocale, _T("."));
		::_tcscat_s(szLocale, szBuf);
	}

	CddnctDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}
