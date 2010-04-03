// CropDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ddnct.h"
#include "CropDlg.h"

// CCropDlg dialog

IMPLEMENT_DYNAMIC(CCropDlg, CDialog)

CCropDlg::CCropDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCropDlg::IDD, pParent)
{
}

CCropDlg::~CCropDlg()
{
}

CCrop CCropDlg::m_crops[] = 
{
	CCrop(_T("���ܲ�"),		0, 15, 1, 10, 0),
	CCrop(_T("���ܲ�"),		0, 18, 1, 13, 0),
	CCrop(_T("����"),		3, 19, 1, 14, 0),
	CCrop(_T("����"),		4, 20, 1, 15, 0),
	CCrop(_T("����"),		5, 21, 1, 16, 0),
	CCrop(_T("����"),		6, 22, 1, 17, 0),
	CCrop(_T("�㶹"),		7, 23, 1, 18, 0),
	CCrop(_T("����"),		8, 25, 1, 20, 0),
	CCrop(_T("�Ϲ�"),		9, 27, 1, 22, 0),
	CCrop(_T("ƻ��"),		10, 20, 2, 21, 9),
	CCrop(_T("��ݮ"),		10, 23, 2, 24, 11),
	CCrop(_T("����"),		11, 26, 2, 28, 13),
	CCrop(_T("�㽶"),		12, 28, 2, 31, 14),
	CCrop(_T("����"),		13, 35, 2, 42, 18),
	CCrop(_T("����"),		14, 28, 3, 37, 16),
	CCrop(_T("����"),		15, 34, 3, 46, 20),
	CCrop(_T("ʯ��"),		16, 37, 3, 52, 22),
	CCrop(_T("����"),		17, 43, 3, 61, 26),
	CCrop(_T("����"),		18, 44, 3, 64, 26),
	CCrop(_T("Ҭ��"),		19, 36, 4, 55, 23),
	CCrop(_T("��«"),		20, 40, 4, 61, 26),
	CCrop(_T("������"),		21, 39, 4, 70, 29),
	CCrop(_T("ӣ��"),		22, 41, 4, 72, 30),
	CCrop(_T("��֦"),		23, 43, 4, 77, 31),
	CCrop(_T("�����"),		24, 45, 4, 81, 33),
	CCrop(_T("���ܹ�"),		25, 19, 2, 26, 11),
	CCrop(_T("����"),		26, 25, 2, 35, 15),
	CCrop(_T("����"),		27, 28, 2, 39, 16),
	CCrop(_T("����"),		28, 26, 3, 41, 18),
	CCrop(_T("Ģ��"),		29, 30, 3, 49, 21),
	CCrop(_T("��÷"),		30, 34, 3, 55, 23),
	CCrop(_T("���"),		31, 36, 3, 58, 25),
	CCrop(_T("â��"),		32, 38, 3, 62, 26),
	// totoal: 33
};


void CCropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL CCropDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_pMDlg = (CddnctDlg *) AfxGetApp()->m_pMainWnd;

	return TRUE;
}

BEGIN_MESSAGE_MAP(CCropDlg, CDialog)
	ON_STN_CLICKED(IDC_BLB, &CCropDlg::OnStnClickedBlb)
	ON_STN_CLICKED(IDC_HLB, &CCropDlg::OnStnClickedHlb)
	ON_STN_CLICKED(IDC_YM, &CCropDlg::OnStnClickedYm)
	ON_STN_CLICKED(IDC_TD, &CCropDlg::OnStnClickedTd)
	ON_STN_CLICKED(IDC_QZ, &CCropDlg::OnStnClickedQz)
	ON_STN_CLICKED(IDC_FQ, &CCropDlg::OnStnClickedFq)
	ON_STN_CLICKED(IDC_WD, &CCropDlg::OnStnClickedWd)
	ON_STN_CLICKED(IDC_LJ, &CCropDlg::OnStnClickedLj)
	ON_STN_CLICKED(IDC_NG, &CCropDlg::OnStnClickedNg)
	ON_STN_CLICKED(IDC_PG, &CCropDlg::OnStnClickedPg)
	ON_STN_CLICKED(IDC_CM, &CCropDlg::OnStnClickedCm)
	ON_STN_CLICKED(IDC_XG, &CCropDlg::OnStnClickedXg)
	ON_STN_CLICKED(IDC_XJ, &CCropDlg::OnStnClickedXj)
	ON_STN_CLICKED(IDC_TZ, &CCropDlg::OnStnClickedTz)
	ON_STN_CLICKED(IDC_CZ, &CCropDlg::OnStnClickedCz)
	ON_STN_CLICKED(IDC_PT, &CCropDlg::OnStnClickedPt)
	ON_STN_CLICKED(IDC_SL, &CCropDlg::OnStnClickedSl)
	ON_STN_CLICKED(IDC_YZ, &CCropDlg::OnStnClickedYz)
	ON_STN_CLICKED(IDC_BL, &CCropDlg::OnStnClickedBl)
	ON_STN_CLICKED(IDC_YEZ, &CCropDlg::OnStnClickedYez)
	ON_STN_CLICKED(IDC_HL, &CCropDlg::OnStnClickedHl)
	ON_STN_CLICKED(IDC_HLG, &CCropDlg::OnStnClickedHlg)
	ON_STN_CLICKED(IDC_YT, &CCropDlg::OnStnClickedYt)
	ON_STN_CLICKED(IDC_LZ, &CCropDlg::OnStnClickedLz)
	ON_STN_CLICKED(IDC_QYG, &CCropDlg::OnStnClickedQyg)
	ON_STN_CLICKED(IDC_HMG, &CCropDlg::OnStnClickedHmg)
	ON_STN_CLICKED(IDC_NM, &CCropDlg::OnStnClickedNm)
	ON_STN_CLICKED(IDC_PP, &CCropDlg::OnStnClickedPp)
	ON_STN_CLICKED(IDC_GZ, &CCropDlg::OnStnClickedGz)
	ON_STN_CLICKED(IDC_MG, &CCropDlg::OnStnClickedMg)
	ON_STN_CLICKED(IDC_YMEI, &CCropDlg::OnStnClickedYmei)
	ON_STN_CLICKED(IDC_GL, &CCropDlg::OnStnClickedGl)
	ON_STN_CLICKED(IDC_MANGG, &CCropDlg::OnStnClickedMangg)
END_MESSAGE_MAP()

// CCropDlg message handlers

void CCropDlg::DisplayInfo(CCrop crop)
{
	m_pMDlg->m_htmlInfoBoxCtrl.ShowWindow(SW_HIDE);
	m_pMDlg->m_htmlInfoBoxCtrl.SetWindowText(crop.InfoStr(m_pMDlg->GetSowingTime()));
	m_pMDlg->m_htmlInfoBoxCtrl.ShowWindow(SW_SHOW);
}

void CCropDlg::OnStnClickedBlb()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[0]);
}

void CCropDlg::OnStnClickedHlb()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[1]);
}

void CCropDlg::OnStnClickedYm()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[2]);
}

void CCropDlg::OnStnClickedTd()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[3]);
}

void CCropDlg::OnStnClickedQz()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[4]);
}

void CCropDlg::OnStnClickedFq()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[5]);
}

void CCropDlg::OnStnClickedWd()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[6]);
}

void CCropDlg::OnStnClickedLj()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[7]);
}

void CCropDlg::OnStnClickedNg()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[8]);
}

void CCropDlg::OnStnClickedPg()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[9]);
}

void CCropDlg::OnStnClickedCm()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[10]);
}

void CCropDlg::OnStnClickedXg()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[11]);
}

void CCropDlg::OnStnClickedXj()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[12]);
}

void CCropDlg::OnStnClickedTz()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[13]);
}

void CCropDlg::OnStnClickedCz()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[14]);
}

void CCropDlg::OnStnClickedPt()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[15]);
}

void CCropDlg::OnStnClickedSl()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[16]);
}

void CCropDlg::OnStnClickedYz()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[17]);
}

void CCropDlg::OnStnClickedBl()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[18]);
}

void CCropDlg::OnStnClickedYez()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[19]);
}

void CCropDlg::OnStnClickedHl()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[20]);
}

void CCropDlg::OnStnClickedHlg()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[21]);
}

void CCropDlg::OnStnClickedYt()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[22]);
}

void CCropDlg::OnStnClickedLz()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[23]);
}

void CCropDlg::OnStnClickedQyg()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[24]);
}

void CCropDlg::OnStnClickedHmg()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[25]);
}

void CCropDlg::OnStnClickedNm()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[26]);
}

void CCropDlg::OnStnClickedPp()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[27]);
}

void CCropDlg::OnStnClickedGz()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[28]);
}

void CCropDlg::OnStnClickedMg()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[29]);
}

void CCropDlg::OnStnClickedYmei()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[30]);
}

void CCropDlg::OnStnClickedGl()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[31]);
}

void CCropDlg::OnStnClickedMangg()
{
	// TODO: Add your control notification handler code here
	DisplayInfo(m_crops[32]);
}
