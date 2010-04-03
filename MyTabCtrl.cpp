// MyTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ddnct.h"
#include "MyTabCtrl.h"
#include "CropDlg.h"
#include "FlowerDlg.h"


// CMyTabCtrl

IMPLEMENT_DYNAMIC(CMyTabCtrl, CTabCtrl)

CMyTabCtrl::CMyTabCtrl()
{
   m_DialogID[0] = IDD_DIALOG_CROP;
   m_DialogID[1] = IDD_DIALOG_FLOWER;


   m_Dialog[0] = new CCropDlg();
   m_Dialog[1] = new CFlowerDlg();

   m_nPageCount = 2;
}

CMyTabCtrl::~CMyTabCtrl()
{
}

BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CMyTabCtrl::OnTcnSelchangeTab)
END_MESSAGE_MAP()

// CMyTabCtrl message handlers

//This function creates the Dialog boxes once
void CMyTabCtrl::InitDialogs()
{
	m_Dialog[0]->Create(m_DialogID[0], GetParent());
	m_Dialog[1]->Create(m_DialogID[1], GetParent());
}

//Selection change event for the class derived from CTabCtrl
void CMyTabCtrl::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	ActivateTabDialogs();
	*pResult = 0;
}

void CMyTabCtrl::ActivateTabDialogs()
{
	int nSel = GetCurSel();
	if (m_Dialog[nSel]->m_hWnd)
		m_Dialog[nSel]->ShowWindow(SW_HIDE);

	CRect l_rectClient;
	CRect l_rectWnd;

	GetClientRect(l_rectClient);
	AdjustRect(FALSE,l_rectClient);
	GetWindowRect(l_rectWnd);
	GetParent()->ScreenToClient(l_rectWnd);
	l_rectClient.OffsetRect(l_rectWnd.left,l_rectWnd.top);
	for (int nCount=0; nCount < m_nPageCount; nCount++) {
		m_Dialog[nCount]->SetWindowPos(&wndTop, l_rectClient.left, l_rectClient.top, l_rectClient.Width(), l_rectClient.Height(), SWP_HIDEWINDOW);
	}
	m_Dialog[nSel]->SetWindowPos(&wndTop, l_rectClient.left, l_rectClient.top, l_rectClient.Width(), l_rectClient.Height(), SWP_SHOWWINDOW);

	m_Dialog[nSel]->ShowWindow(SW_SHOW);
	
	((CddnctDlg *) AfxGetApp()->m_pMainWnd)->DisplayGreetings();
}



