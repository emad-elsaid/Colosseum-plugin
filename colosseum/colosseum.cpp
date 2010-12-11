// colosseum.cpp : Implementation of CColosseumApp and DLL registration.

#include "stdafx.h"
#include "colosseum.h"
#include "IFCEngineInteract.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern	char	* g_ifcSchemaName;

CColosseumApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0xEAB0C469, 0xFB77, 0x4B34, { 0x91, 0x2F, 0xB4, 0xF0, 0xF3, 0x98, 0xEB, 0xF8 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CColosseumApp::InitInstance - DLL initialization

BOOL CColosseumApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
		
		/* Intialize the schema name*/
		g_ifcSchemaName = new char[strlen("E:\\Dev\\Colosseum-plugin\\Debug\\IFC2X3_TC1.exp")+1];
		memcpy(g_ifcSchemaName, "E:\\Dev\\Colosseum-plugin\\Debug\\IFC2X3_TC1.exp", strlen("E:\\Dev\\Colosseum-plugin\\Debug\\IFC2X3_TC1.exp")+1);

	}

	return bInit;
}



// CColosseumApp::ExitInstance - DLL termination

int CColosseumApp::ExitInstance()
{
	// TODO: Add your own module termination code here.
	delete g_ifcSchemaName;
	g_ifcSchemaName = NULL;
	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
