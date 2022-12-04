
// CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "InfixEval.h"
#include <iostream>
#include <string>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_output(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_output);
	DDX_Control(pDX, IDC_BUTTON0, m_button0);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_BUTTON3, m_button3);
	DDX_Control(pDX, IDC_BUTTON4, m_button4);
	DDX_Control(pDX, IDC_BUTTON5, m_button5);
	DDX_Control(pDX, IDC_BUTTON6, m_button6);
	DDX_Control(pDX, IDC_BUTTON7, m_button7);
	DDX_Control(pDX, IDC_BUTTON8, m_button8);
	DDX_Control(pDX, IDC_BUTTON9, m_button9);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_out);
	DDX_Control(pDX, IDC_BUTTON_MULTI, m_button_multi);
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, m_button_divide);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_button_add);
	DDX_Control(pDX, IDC_BUTTON_SUB, m_button_sub);
	DDX_Control(pDX, IDC_BUTTON_POWER, m_button_power);
	DDX_Control(pDX, IDC_BUTTON_REMAIN, m_button_remain);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, m_button_clear);
	DDX_Control(pDX, IDC_BUTTON_EQUAL, m_button_equal);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCalculatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_MULTI, &CCalculatorDlg::OnBnClickedButtonMulti)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_REMAIN, &CCalculatorDlg::OnBnClickedButtonRemain)
	ON_BN_CLICKED(IDC_BUTTON_POWER, &CCalculatorDlg::OnBnClickedButtonPower)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CCalculatorDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CCalculatorDlg::OnBnClickedButtonDot)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_font.CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Microsoft Sans Serif"));
	m_button0.SetFont(&m_font);
	m_button1.SetFont(&m_font);
	m_button2.SetFont(&m_font);
	m_button3.SetFont(&m_font);
	m_button4.SetFont(&m_font);
	m_button5.SetFont(&m_font);
	m_button6.SetFont(&m_font);
	m_button7.SetFont(&m_font);
	m_button8.SetFont(&m_font);
	m_button9.SetFont(&m_font);
	m_button_multi.SetFont(&m_font);
	m_button_divide.SetFont(&m_font);
	m_button_add.SetFont(&m_font);
	m_button_sub.SetFont(&m_font);
	m_button_power.SetFont(&m_font);
	m_button_remain.SetFont(&m_font);
	m_button_equal.SetFont(&m_font);
	m_button_clear.SetFont(&m_font);

	m_font2.CreateFont(35, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Microsoft Sans Serif"));
	m_out.SetFont(&m_font2);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CCalculatorDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}



void CCalculatorDlg::addDigit(char digit)
{
	if (m_output == '0')
	{
		m_output = digit;
	}
	else if (check1 > 1)
	{
		
	}
	else
	{
		m_output += digit;
	}
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedButton1()
{
	if (check1 > 1){check1 = 0;}
	addDigit('1');
}


void CCalculatorDlg::OnBnClickedButton2()
{
	if (check1 > 1) { check1 = 0; }
	addDigit('2');
}


void CCalculatorDlg::OnBnClickedButton3()
{
	if (check1 > 1) { check1 = 0; }
	addDigit('3');
}


void CCalculatorDlg::OnBnClickedButton4()
{
	if (check1 > 1) { check1 = 0; }
	addDigit('4');
}


void CCalculatorDlg::OnBnClickedButton5()
{
	if (check1 > 1) { check1 = 0; }
	addDigit('5');
}


void CCalculatorDlg::OnBnClickedButton6()
{
	if (check1 > 1) { check1 = 0; }
	addDigit('6');
}


void CCalculatorDlg::OnBnClickedButton7()
{
	if (check1 > 1) { check1 = 0; }
	addDigit('7');
}


void CCalculatorDlg::OnBnClickedButton8()
{
	if (check1 > 1) { check1 = 0; }
	addDigit('8');
}


void CCalculatorDlg::OnBnClickedButton9()
{
	if (check1 > 1) { check1 = 0; }
	addDigit('9');
}


void CCalculatorDlg::OnBnClickedButton0()
{
	if (check1 > 1) { check1 = 0; }
	addDigit('0');
}


void CCalculatorDlg::OnBnClickedButtonDot()
{
	addDigit('.');
}


void CCalculatorDlg::OnBnClickedButtonMulti()
{
	check1++;
	addDigit(' ');
	addDigit('*');
	addDigit(' ');
}


void CCalculatorDlg::OnBnClickedButtonDivide()
{
	check1++;
	addDigit(' ');
	addDigit('/');
	addDigit(' ');
}


void CCalculatorDlg::OnBnClickedButtonAdd()
{
	check1++;
	addDigit(' ');
	addDigit('+');
	addDigit(' ');
}


void CCalculatorDlg::OnBnClickedButtonRemain()
{
	check1++;
	addDigit(' ');
	addDigit('%');
	addDigit(' ');
}


void CCalculatorDlg::OnBnClickedButtonPower()
{
	check1++;
	addDigit(' ');
	addDigit('^');
	addDigit(' ');
}


void CCalculatorDlg::OnBnClickedButtonSub()
{
	check1++;
	addDigit(' ');
	addDigit('-');
	addDigit(' ');
}


void CCalculatorDlg::OnBnClickedButtonClear()
{
	m_output = '0';
	addDigit('0');
}


void CCalculatorDlg::OnBnClickedButtonEqual()
{
	
	
	if (m_output != (" + ") && m_output != (" - ") && m_output != (" * ") && m_output != (" / ") && m_output != (" ^ ") && m_output != (" % "))
	{
		float n;
		std::string str(CW2A(m_output.GetString(), CP_UTF8));
		n = evaluate(str);
		m_output = (CString)(std::to_wstring(n).c_str());
		UpdateData(FALSE);
	}
	else
	{
		
	}
	
}
