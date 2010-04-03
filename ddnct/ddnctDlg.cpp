
// ddnctDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ddnct.h"
#include "ddnctDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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
	_T("<br><br><big> 欢迎使用 dd81 开心农场收获时间计算器！</big><br><br>")
	_T("<br>")
	_T("<br>")
	_T("<b> 使用方法：</b>")
	_T("<br>")
	_T(" 1. 在上方设定播种时间；<br>")
	_T(" 2. 点击左方的作物/鲜花；<br>")
	_T(" 3. 此处将显示作物/鲜花的相关信息和收获时间。<br>")
	_T("<br>")
	_T("<br>")
	_T(" 注：作物/鲜花相关信息以 <font color=\"blue\"><u><a href=\"http://www.dd81.com/club\">dd81</a></u>")
	_T("<font color=\"black\"> 版 </font> <font color=\"blue\">")
	_T("<u><a href=\"http://www.dd81.com/uchome/userapp.php?id=1021978\">开心农场</a></u></font>为准。");

const CString wanju_infostr = 
	_T("<br><b><font color=\"Purple\" size=\"+8\"> 神秘玩具 <br><br></font></b>")
	_T("任意5种作物果实各15个<br>即可在兑换商店兑换1粒玩具种子<br>");

const CString ps_infostr = 
	_T("<br><b><font color=\"Purple\" size=\"+8\"> 胖子 <br><br></font></b>")
	_T("亲爱的朋友，现在就点击")
	_T("<font color=\"blue\"><u><a href=\"http://www.dd81.com/club/viewthread.php?tid=83005\">这里</a></u></font>")
	_T("加入 dd81 照片区，你可以在那里看到更多这样的胖子！<br><br>");


// CddnctDlg 对话框




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


// CddnctDlg 消息处理程序

BOOL CddnctDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
    m_TabCtrl.InitDialogs();

    m_TabCtrl.InsertItem(0, _T("作物"));
    m_TabCtrl.InsertItem(1, _T("鲜花及其它"));

    m_TabCtrl.ActivateTabDialogs();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CddnctDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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

