// colosseumCtrl.cpp : Implementation of the CcolosseumCtrl ActiveX Control class.

#include "stdafx.h"
#include "colosseum.h"
#include "colosseumCtrl.h"
#include "colosseumPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CcolosseumCtrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CcolosseumCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// Dispatch map

BEGIN_DISPATCH_MAP(CcolosseumCtrl, COleControl)
	DISP_FUNCTION_ID(CcolosseumCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// Event map

BEGIN_EVENT_MAP(CcolosseumCtrl, COleControl)
END_EVENT_MAP()



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CcolosseumCtrl, 1)
	PROPPAGEID(CcolosseumPropPage::guid)
END_PROPPAGEIDS(CcolosseumCtrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CcolosseumCtrl, "COLOSSEUM.colosseumCtrl.1",
	0x70217189, 0x66e8, 0x4874, 0x9f, 0xd2, 0x53, 0x52, 0xfd, 0xf4, 0x67, 0x34)



// Type library ID and version

IMPLEMENT_OLETYPELIB(CcolosseumCtrl, _tlid, _wVerMajor, _wVerMinor)



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

IMPLEMENT_OLECTLTYPE(CcolosseumCtrl, IDS_COLOSSEUM, _dwcolosseumOleMisc)



// CcolosseumCtrl::CcolosseumCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CcolosseumCtrl

BOOL CcolosseumCtrl::CcolosseumCtrlFactory::UpdateRegistry(BOOL bRegister)
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



// CcolosseumCtrl::CcolosseumCtrl - Constructor

CcolosseumCtrl::CcolosseumCtrl()
{
	InitializeIIDs(&IID_Dcolosseum, &IID_DcolosseumEvents);
	// TODO: Initialize your control's instance data here.
}



// CcolosseumCtrl::~CcolosseumCtrl - Destructor

CcolosseumCtrl::~CcolosseumCtrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CcolosseumCtrl::OnDraw - Drawing function

void CcolosseumCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CcolosseumCtrl::DoPropExchange - Persistence support

void CcolosseumCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}



// CcolosseumCtrl::GetControlFlags -
// Flags to customize MFC's implementation of ActiveX controls.
//
DWORD CcolosseumCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// The control will not be redrawn when making the transition
	// between the active and inactivate state.
	dwFlags |= noFlickerActivate;
	return dwFlags;
}



// CcolosseumCtrl::OnResetState - Reset control to default state

void CcolosseumCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}



// CcolosseumCtrl::AboutBox - Display an "About" box to the user

void CcolosseumCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_COLOSSEUM);
	dlgAbout.DoModal();
}



// CcolosseumCtrl message handlers
