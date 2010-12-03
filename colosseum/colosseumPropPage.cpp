// colosseumPropPage.cpp : Implementation of the CcolosseumPropPage property page class.

#include "stdafx.h"
#include "colosseum.h"
#include "colosseumPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CcolosseumPropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CcolosseumPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CcolosseumPropPage, "COLOSSEUM.colosseumPropPage.1",
	0x145f60e5, 0xa334, 0x466d, 0xad, 0x94, 0x91, 0xfa, 0x86, 0x87, 0x93, 0x1d)



// CcolosseumPropPage::CcolosseumPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CcolosseumPropPage

BOOL CcolosseumPropPage::CcolosseumPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_COLOSSEUM_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CcolosseumPropPage::CcolosseumPropPage - Constructor

CcolosseumPropPage::CcolosseumPropPage() :
	COlePropertyPage(IDD, IDS_COLOSSEUM_PPG_CAPTION)
{
}



// CcolosseumPropPage::DoDataExchange - Moves data between page and properties

void CcolosseumPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CcolosseumPropPage message handlers
