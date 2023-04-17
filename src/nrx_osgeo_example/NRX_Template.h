// NRX_Template.h : main header file for the NRX_Template DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "arxHeaders.h"
#include "AcExtensionModule.h"


void ogr_test();
extern "C" __declspec(dllexport) AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
    switch (msg)
    {
    case AcRx::kInitAppMsg:
        acrxDynamicLinker->unlockApplication(appId);
        acrxDynamicLinker->registerAppMDIAware(appId);

        acedRegCmds->addCommand(L"TEST_OSGEO",
            L"_OGR_RUN_CPP",
            L"OGR_RUN_CPP",
            ACRX_CMD_TRANSPARENT,
            ogr_test);
        break;

    case AcRx::kUnloadAppMsg:
        acedRegCmds->removeGroup(L"TEST_OSGEO");
        break;
    }

    return AcRx::kRetOK;
}