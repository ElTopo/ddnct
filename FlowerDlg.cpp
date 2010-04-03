// FlowerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ddnct.h"
#include "FlowerDlg.h"


// CFlowerDlg dialog
CCrop CFlowerDlg::m_crops[] = 
{
	CCrop(_T("红色玫瑰"),		0, 21, 1, 16, 0),
	CCrop(_T("黄色太阳花"),	0, 30, 1, 24, 0),
	CCrop(_T("白色康乃馨"),	1, 33, 1, 26, 0),
	CCrop(_T("紫色郁金香"),	2, 35, 1, 27, 0),
	CCrop(_T("白色水仙"),		3, 36, 1, 28, 0),
	CCrop(_T("白色风信子"),	4, 38, 1, 30, 0),
	CCrop(_T("紫色紫罗兰"),	5, 39, 1, 32, 0),
	CCrop(_T("白色百合"),		6, 42, 1, 36, 0),
	// totoal: 8
};

IMPLEMENT_DYNAMIC(CFlowerDlg, CDialog)

CFlowerDlg::CFlowerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFlowerDlg::IDD, pParent)
{
	m_pMDlg = (CddnctDlg *) AfxGetApp()->m_pMainWnd;
}

CFlowerDlg::~CFlowerDlg()
{
}

void CFlowerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BOOL CFlowerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_pMDlg = (CddnctDlg *) AfxGetApp()->m_pMainWnd;

	return TRUE;
}

BEGIN_MESSAGE_MAP(CFlowerDlg, CDialog)
	ON_STN_CLICKED(IDC_MEIG, &CFlowerDlg::OnStnClickedMeig)
	ON_STN_CLICKED(IDC_TYH, &CFlowerDlg::OnStnClickedTyh)
	ON_STN_CLICKED(IDC_KNX, &CFlowerDlg::OnStnClickedKnx)
	ON_STN_CLICKED(IDC_YJX, &CFlowerDlg::OnStnClickedYjx)
	ON_STN_CLICKED(IDC_SX, &CFlowerDlg::OnStnClickedSx)
	ON_STN_CLICKED(IDC_FXZ, &CFlowerDlg::OnStnClickedFxz)
	ON_STN_CLICKED(IDC_ZLL, &CFlowerDlg::OnStnClickedZll)
	ON_STN_CLICKED(IDC_BH, &CFlowerDlg::OnStnClickedBh)
	ON_STN_CLICKED(IDC_WANJU, &CFlowerDlg::OnStnClickedWanju)
	ON_STN_CLICKED(IDC_PZ, &CFlowerDlg::OnStnClickedPz)
END_MESSAGE_MAP()


// CFlowerDlg message handlers
void CFlowerDlg::DisplayInfo(CCrop crop)
{
	m_pMDlg->m_htmlInfoBoxCtrl.ShowWindow(SW_HIDE);
	m_pMDlg->m_htmlInfoBoxCtrl.SetWindowText(crop.InfoStr(m_pMDlg->GetSowingTime(), true));
	m_pMDlg->m_htmlInfoBoxCtrl.ShowWindow(SW_SHOW);
}


void CFlowerDlg::OnStnClickedMeig()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[0]);
}

void CFlowerDlg::OnStnClickedTyh()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[1]);
}

void CFlowerDlg::OnStnClickedKnx()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[2]);
}

void CFlowerDlg::OnStnClickedYjx()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[3]);
}

void CFlowerDlg::OnStnClickedSx()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[4]);
}

void CFlowerDlg::OnStnClickedFxz()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[5]);
}

void CFlowerDlg::OnStnClickedZll()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[6]);
}

void CFlowerDlg::OnStnClickedBh()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[7]);
}

void CFlowerDlg::OnStnClickedWanju()
{
	// TODO: Add your control notification handler code here
	m_pMDlg->DisplayWanJueInfo();
}

void CFlowerDlg::OnStnClickedPz()
{
	// TODO: Add your control notification handler code here
	m_pMDlg->DisplayPZInfo();
}
