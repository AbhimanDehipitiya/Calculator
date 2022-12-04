
// CalculatorDlg.h : header file
//

#pragma once


// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonMulti();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonRemain();
	afx_msg void OnBnClickedButtonPower();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonDot();
	CString m_output;

private:
	CFont m_font;
	CFont m_font2;
	void addDigit(char digit);
	int numbers[50], tn = -1, to = -1;
	char op[50], exp[50];

public:
	CEdit m_out;
	CButton m_button0;
	CButton m_button1;
	CButton m_button2;
	CButton m_button3;
	CButton m_button4;
	CButton m_button5;
	CButton m_button6;
	CButton m_button7;
	CButton m_button8;
	CButton m_button9;
	CButton m_button_multi;
	CButton m_button_divide;
	CButton m_button_add;
	CButton m_button_sub;
	CButton m_button_power;
	CButton m_button_remain;
	CButton m_button_clear;
	CButton m_button_equal;
};
