#pragma once

#include "ddnctDlg.h"
#include "Crop.h"

// CFlowerDlg dialog

class CFlowerDlg : public CDialog
{
	DECLARE_DYNAMIC(CFlowerDlg)

public:
	CFlowerDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFlowerDlg();

	CddnctDlg *m_pMDlg;

// Dialog Data
	enum { IDD = IDD_DIALOG_FLOWER };

	static CCrop m_crops[];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	void DisplayInfo(CCrop crop);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedMeig();
	afx_msg void OnStnClickedTyh();
	afx_msg void OnStnClickedKnx();
	afx_msg void OnStnClickedYjx();
	afx_msg void OnStnClickedSx();
	afx_msg void OnStnClickedFxz();
	afx_msg void OnStnClickedZll();
	afx_msg void OnStnClickedBh();
	afx_msg void OnStnClickedWanju();
	afx_msg void OnStnClickedPz();
};
