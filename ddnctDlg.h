
// ddnctDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "mytabctrl.h"
#include "xhtmlstatic.h"
#include "afxdtctl.h"


// CddnctDlg �Ի���
class CddnctDlg : public CDialog
{
// ����
public:
	CddnctDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DDNCT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	CTime& GetSowingTime();


// ʵ��
protected:
	HICON m_hIcon;

	CDateTimeCtrl m_dateCtrl;
	CDateTimeCtrl m_timeCtrl;

	CTime m_tmSowing;

	// ���ɵ���Ϣӳ�亯��
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
