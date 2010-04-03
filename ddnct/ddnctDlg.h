
// ddnctDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "mytabctrl.h"
#include "xhtmlstatic.h"
#include "afxdtctl.h"


// CddnctDlg 对话框
class CddnctDlg : public CDialog
{
// 构造
public:
	CddnctDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DDNCT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
	CTime& GetSowingTime();


// 实现
protected:
	HICON m_hIcon;

	CDateTimeCtrl m_dateCtrl;
	CDateTimeCtrl m_timeCtrl;

	CTime m_tmSowing;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonGetcurrent();
	CMyTabCtrl m_TabCtrl;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	CXHTMLStatic m_htmlInfoBoxCtrl;

	void DisplayGreetings();
	void DisplayWanJueInfo();
	void DisplayPZInfo();
};
