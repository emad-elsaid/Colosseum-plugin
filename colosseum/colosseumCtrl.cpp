// colosseumCtrl.cpp : Implementation of the CColosseumCtrl ActiveX Control class.

#include "stdafx.h"
#include "colosseum.h"
#include "colosseumCtrl.h"
#include "colosseumPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CColosseumCtrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CColosseumCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// Dispatch map

BEGIN_DISPATCH_MAP(CColosseumCtrl, COleControl)
	DISP_FUNCTION_ID(CColosseumCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// Event map

BEGIN_EVENT_MAP(CColosseumCtrl, COleControl)
END_EVENT_MAP()



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CColosseumCtrl, 1)
	PROPPAGEID(CcolosseumPropPage::guid)
END_PROPPAGEIDS(CColosseumCtrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CColosseumCtrl, "COLOSSEUM.colosseumCtrl.1",
	0x70217189, 0x66e8, 0x4874, 0x9f, 0xd2, 0x53, 0x52, 0xfd, 0xf4, 0x67, 0x34)



// Type library ID and version

IMPLEMENT_OLETYPELIB(CColosseumCtrl, _tlid, _wVerMajor, _wVerMinor)



// Interface IDs

const IID BASED_CODE IID_Dcolosseum =
		{ 0xE8B8A0AD, 0x761C, 0x4631, { 0x88, 0xCF, 0xD5, 0xD2, 0xDD, 0xEA, 0xEE, 0x79 } };
const IID BASED_CODE IID_DcolosseumEvents =
		{ 0xE9D4851E, 0x590E, 0x4C56, { 0x9C, 0xEF, 0x9E, 0xC4, 0x95, 0x96, 0x1E, 0xDD } };



// Control type information

static const DWORD BASED_CODE _dwcolosseumOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CColosseumCtrl, IDS_COLOSSEUM, _dwcolosseumOleMisc)



// CColosseumCtrl::CColosseumCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CColosseumCtrl

BOOL CColosseumCtrl::CColosseumCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_COLOSSEUM,
			IDB_COLOSSEUM,
			afxRegApartmentThreading,
			_dwcolosseumOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CColosseumCtrl::CColosseumCtrl - Constructor

CColosseumCtrl::CColosseumCtrl() : m_width(0), m_height(0), m_server("")
{
	InitializeIIDs(&IID_Dcolosseum, &IID_DcolosseumEvents);
	// TODO: Initialize your control's instance data here.
	
}




// CColosseumCtrl::~CColosseumCtrl - Destructor

CColosseumCtrl::~CColosseumCtrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CColosseumCtrl::OnDraw - Drawing function

void CColosseumCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
	m_width = rcBounds.Width();
	m_height = rcBounds.Height();
}



// CColosseumCtrl::DoPropExchange - Persistence support

void CColosseumCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
	// TODO: Call PX_ functions for each persistent custom property.
	
	PX_String(pPX, _T("server"), m_server, L"");
}



// CColosseumCtrl::GetControlFlags -
// Flags to customize MFC's implementation of ActiveX controls.
//
DWORD CColosseumCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// The control will not be redrawn when making the transition
	// between the active and inactivate state.
	dwFlags |= noFlickerActivate;
	return dwFlags;
}



// CColosseumCtrl::OnResetState - Reset control to default state

void CColosseumCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
	
	// TODO: Reset any other control state here.
}



// CColosseumCtrl::AboutBox - Display an "About" box to the user

void CColosseumCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_COLOSSEUM);
	dlgAbout.DoModal();
}


// CColosseumCtrl message handlers

LONG CColosseumCtrl::GetHeight() const
{
	return m_height;
}

LONG CColosseumCtrl::GetWidth() const
{
	return m_width;
}

BSTR CColosseumCtrl::GetServer() const
{
	return m_server.AllocSysString();
}