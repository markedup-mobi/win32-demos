// MarkedUp.TestApps.Win32.Console (Native CPP).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MarkedUp.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	/*
	* IMPORTANT: In order to run this application properly, you will need to do the following:
	*	1. Replace "ENTER YOUR API KEY HERE" with your own MarkedUp API Key value, which you can get by registering at https://markedup.com/.
	*     You can use multiple API keys if you wish to have your MarkedUp data populated to multiple "apps" on your dashboard.
	*
	*	2. Replace the "YOUR AREA IN THE REGISTRY" with an arbtirary registry key name that MarkedUp
	*	   will use for storing opt-out / opt-in preferences for individual users. This data is saved under HK_LOCAL_USER.
	*/
	const TCHAR* apiKey[] = { _T("ENTER YOUR API KEY HERE") };
	const TCHAR* registryArea = _T("YOUR AREA IN THE REGISTRY");

	/* INITIALIZE MARKEDUP SDK */
	MK_Initialize_Multiple(apiKey, registryArea);

	MK_Tuple Items[] = { { _T("Param1"), _T("Value1") }, { _T("Param2"), _T("Value2") } };
	MK_ParamDictionary dict;
	dict.ItemCount = 2;
	dict.Items = Items;

	wcout << "Initializing MarkedUp" << endl; 

	MK_EnterPage(_T("HelloWorld.Console")); //Fires the EnterPage event - lets MarkedUp know which piece of UI we've entered
	MK_Trace_State(_T("Finished initializing"), &dict); //Creates a diagnostic log with log level "Trace" and includes some application state defined in the MK_ParamDictionary defined earlier
	

	wcout << "Firing an event." << endl;

	MK_SessionEvent_State(_T("Some Event"), &dict); //Declares a user-defined event called "Some Event" and includes some parameters for this event defined in the MK_ParamDictionary defined earlier

	for(int i = 0; i < dict.ItemCount; i++){
		wcout << "Param" << i << ": {" << Items[i].Key << "," << Items[i].Value << " }" << endl;
	}

	int stop;
	cin >> stop;

	MK_SessionEnd(); //Let's MarkedUp know that this user's session has ended - important for computing time spent in app
	MK_AppExit(); //Let's MarkedUp know that the app is exiting

	MK_Unload(); //Unload the MarkedUp DLLs

	wcout << "Checking for memory leaks..." << endl;
	_CrtDumpMemoryLeaks();

	wcout << "Press any key to exit." << endl;
	cin >> stop;

	return 0;
}

