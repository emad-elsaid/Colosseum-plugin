#pragma once

// colosseumCtrl.h : Declaration of the CColosseumCtrl ActiveX Control class.


// CColosseumCtrl : See colosseumCtrl.cpp for implementation.

class CColosseumCtrl : public COleControl
{
	DECLARE_DYNCREATE(CColosseumCtrl)

// Constructor
public:
	CColosseumCtrl();
	
// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();
	

	
// Implementation
protected:
	~CColosseumCtrl();

	DECLARE_OLECREATE_EX(CColosseumCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CColosseumCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CColosseumCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CColosseumCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	DECLARE_EVENT_MAP()

//Attributes or Properties
	LONG m_width;
	LONG m_height;
	CString m_server;


// Dispatch and event IDs

protected:
	
	LONG GetWidth(void) const ; 
	//void SetWidth(LONG newVal);
	LONG GetHeight(void) const ;
	//void SetHeight(LONG newVal);
	BSTR GetServer(void) const;
	//void Setserver(LPCTSTR newVal);
};

