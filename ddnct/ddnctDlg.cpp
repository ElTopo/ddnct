
// ddnctDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ddnct.h"
#include "ddnctDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// const strings
const CString def_greeting = 
	_T("<br><br><big> ��ӭʹ�� dd81 ����ũ���ջ�ʱ���������</big><br><br>")
	_T("<br>")
	_T("<br>")
	_T("<b> ʹ�÷�����</b>")
	_T("<br>")
	_T(" 1. ���Ϸ��趨����ʱ�䣻<br>")
	_T(" 2. ����󷽵�����/�ʻ���<br>")
	_T(" 3. �˴�����ʾ����/�ʻ��������Ϣ���ջ�ʱ�䡣<br>")
	_T("<br>")
	_T("<br>")
	_T(" ע������/�ʻ������Ϣ�� <font color=\"blue\"><u><a href=\"http://www.dd81.com/club\">dd81</a></u>")
	_T("<font color=\"black\"> �� </font> <font color=\"blue\">")
	_T("<u><a href=\"http://www.dd81.com/uchome/userapp.php?id=1021978\">����ũ��</a></u></font>Ϊ׼��");

const CString wanju_infostr = 
	_T("<br><b><font color=\"Purple\" size=\"+8\"> ������� <br><br></font></b>")
	_T("����5�������ʵ��15��<br>�����ڶһ��̵�һ�1���������<br>");

const CString ps_infostr = 
	_T("<br><b><font color=\"Purple\" size=\"+8\"> ���� <br><br></font></b>")
	_T("�װ������ѣ����ھ͵��")
	_T("<font color=\"blue\"><u><a href=\"http://www.dd81.com/club/viewthread.php?tid=83005\">����</a></u></font>")
	_T("���� dd81 ��Ƭ��������������￴���������������ӣ�<br><br>");


// CddnctDlg �Ի���




CddnctDlg::CddnctDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CddnctDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CddnctDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_TabCtrl);
	DDX_Control(pDX, IDC_INFOBOX, m_htmlInfoBoxCtrl);
	DDX_Control(pDX, IDC_DATETIMEPICKER_DATE, m_dateCtrl);
	DDX_Control(pDX, IDC_DATETIMEPICKER_TIME, m_timeCtrl);
}

BEGIN_MESSAGE_MAP(CddnctDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CddnctDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CddnctDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_GETCURRENT, &CddnctDlg::OnBnClickedButtonGetcurrent)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CddnctDlg::OnTcnSelchangeTab)
END_MESSAGE_MAP()


// CddnctDlg ��Ϣ�������

BOOL CddnctDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    m_TabCtrl.InitDialogs();

    m_TabCtrl.InsertItem(0, _T("����"));
    m_TabCtrl.InsertItem(1, _T("�ʻ�������"));

    m_TabCtrl.ActivateTabDialogs();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CddnctDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CddnctDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CddnctDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CddnctDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// OnOK();
}

void CddnctDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CddnctDlg::OnBnClickedButtonGetcurrent()
{
	// TODO: Add your control notification handler code here
	CTime tm = CTime::GetCurrentTime();
	m_dateCtrl.SetTime(&tm);
	m_timeCtrl.SetTime(&tm);
}


void CddnctDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	m_TabCtrl.OnTcnSelchangeTab(pNMHDR, pResult);
}

CTime& CddnctDlg::GetSowingTime() 
{
	CTime dt, tm;
	m_dateCtrl.GetTime(dt);
	m_timeCtrl.GetTime(tm);

	m_tmSowing = CTime(dt.GetYear(), dt.GetMonth(), dt.GetDay(), tm.GetHour(), tm.GetMinute(), tm.GetSecond());
	return m_tmSowing;
}

void CddnctDlg::DisplayGreetings()
{
	m_htmlInfoBoxCtrl.ShowWindow(SW_HIDE);
	m_htmlInfoBoxCtrl.SetWindowText(def_greeting);
	m_htmlInfoBoxCtrl.ShowWindow(SW_SHOW);
}

void CddnctDlg::DisplayWanJueInfo()
{
	m_htmlInfoBoxCtrl.ShowWindow(SW_HIDE);
	m_htmlInfoBoxCtrl.SetWindowText(wanju_infostr);
	m_htmlInfoBoxCtrl.ShowWindow(SW_SHOW);
}

void CddnctDlg::DisplayPZInfo()
{
	m_htmlInfoBoxCtrl.ShowWindow(SW_HIDE);
	m_htmlInfoBoxCtrl.SetWindowText(ps_infostr);
	m_htmlInfoBoxCtrl.ShowWindow(SW_SHOW);
}

