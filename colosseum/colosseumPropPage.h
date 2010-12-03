#pragma once

// colosseumPropPage.h : Declaration of the CcolosseumPropPage property page class.


// CcolosseumPropPage : See colosseumPropPage.cpp for implementation.

class CcolosseumPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CcolosseumPropPage)
	DECLARE_OLECREATE_EX(CcolosseumPropPage)

// Constructor
public:
	CcolosseumPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_COLOSSEUM };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

