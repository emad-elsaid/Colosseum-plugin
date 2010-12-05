#pragma once

// colosseumCtrl.h : Declaration of the CcolosseumCtrl ActiveX Control class.


// CcolosseumCtrl : See colosseumCtrl.cpp for implementation.

class CcolosseumCtrl : public COleControl
{
	DECLARE_DYNCREATE(CcolosseumCtrl)

// Constructor
public:
	CcolosseumCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();

// Implementation
protected:
	~CcolosseumCtrl();

	DECLARE_OLECREATE_EX(CcolosseumCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CcolosseumCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CcolosseumCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CcolosseumCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		dispidserver = 3,
		dispidheight = 2,
		dispidwidth = 1
	};
protected:
	LONG Getwidth(void);
	void Setwidth(LONG newVal);
	LONG Getheight(void);
	void Setheight(LONG newVal);
	BSTR Getserver(void);
	void Setserver(LPCTSTR newVal);
};

