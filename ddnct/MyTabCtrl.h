#pragma once


// CMyTabCtrl

class CMyTabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTabCtrl)

public:
	CMyTabCtrl();
	virtual ~CMyTabCtrl();

	//Array to hold the list of dialog boxes/tab pages for CTabCtrl
	int m_nPageCount;
	int m_DialogID[2];
	
	//CDialog Array Variable to hold the dialogs 
	CDialog *m_Dialog[2];
	
	//Function to Create the dialog boxes during startup
	void InitDialogs();
	
	//Function to activate the tab dialog boxes
	void ActivateTabDialogs();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};


