#pragma once

#include "ddnctDlg.h"
#include "Crop.h"

// CCropDlg dialog

class CCropDlg : public CDialog
{
	DECLARE_DYNAMIC(CCropDlg)

public:
	CCropDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCropDlg();

	CddnctDlg *m_pMDlg;

// Dialog Data
	enum { IDD = IDD_DIALOG_CROP };

	static CCrop m_crops[];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	void DisplayInfo(CCrop crop);
	

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedBlb();
	afx_msg void OnStnClickedHlb();
	afx_msg void OnStnClickedYm();
	afx_msg void OnStnClickedTd();
	afx_msg void OnStnClickedQz();
	afx_msg void OnStnClickedFq();
	afx_msg void OnStnClickedWd();
	afx_msg void OnStnClickedLj();
	afx_msg void OnStnClickedNg();
	afx_msg void OnStnClickedPg();
	afx_msg void OnStnClickedCm();
	afx_msg void OnStnClickedXg();
	afx_msg void OnStnClickedXj();
	afx_msg void OnStnClickedTz();
	afx_msg void OnStnClickedCz();
	afx_msg void OnStnClickedPt();
	afx_msg void OnStnClickedSl();
	afx_msg void OnStnClickedYz();
	afx_msg void OnStnClickedBl();
	afx_msg void OnStnClickedYez();
	afx_msg void OnStnClickedHl();
	afx_msg void OnStnClickedHlg();
	afx_msg void OnStnClickedYt();
	afx_msg void OnStnClickedLz();
	afx_msg void OnStnClickedQyg();
	afx_msg void OnStnClickedHmg();
	afx_msg void OnStnClickedNm();
	afx_msg void OnStnClickedPp();
	afx_msg void OnStnClickedGz();
	afx_msg void OnStnClickedMg();
	afx_msg void OnStnClickedYmei();
	afx_msg void OnStnClickedGl();
	afx_msg void OnStnClickedMangg();
};
