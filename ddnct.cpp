
// ddnct.cpp : ����Ӧ�ó��������Ϊ��
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


// CddnctApp ����

CddnctApp::CddnctApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CddnctApp ����

CddnctApp theApp;


// CddnctApp ��ʼ��

BOOL CddnctApp::InitInstance()
{
	CWinAppEx::InitInstance();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

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
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
