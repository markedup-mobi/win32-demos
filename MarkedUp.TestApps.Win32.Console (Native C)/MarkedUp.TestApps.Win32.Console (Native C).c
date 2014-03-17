// MarkedUp.TestApps.Win32.Console (Native C).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


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

	MK_ParamDictionary dict;
	int stop,i = 0;
	MK_Tuple *Items = malloc(2 * sizeof (MK_Tuple));
	Items[0].Key = _T("Param1");
	Items[0].Value = _T("Value1");
	Items[1].Key = _T("Param2");
	Items[1].Value = _T("Value2");
	
	dict.ItemCount = 2;
	dict.Items = Items;

	printf("Hi there! Thanks for testing MarkedUp \r\n");
	printf("Initializing MarkedUp\r\n");

	/* INITIALIZE MARKEDUP SDK */
	MK_Initialize(apiKey[0], registryArea);

	MK_EnterPage(_T("HelloWorld.Console")); //Fires the EnterPage event - lets MarkedUp know which piece of UI we've entered

	MK_Trace_State(_T("Finished initializing"), &dict); //Creates a diagnostic log with log level "Trace" and includes some application state defined in the MK_ParamDictionary defined earlier
	MK_SessionEvent_State(_T("Some Event"), &dict); //Declares a user-defined event called "Some Event" and includes some parameters for this event defined in the MK_ParamDictionary defined earlier

	

	printf("Firing an event: \r\n");
	printf("Parameters: %d\r\n", dict.ItemCount);


	for (i = 0; i < dict.ItemCount; i++){
		wprintf_s(_T("Param %i : { %s, %s }\r\n"), i, Items[i].Key, Items[i].Value);
	}
	printf("Finished. Press enter to exit. \r\n");
	MK_SessionEnd(); //Let's MarkedUp know that this user's session has ended - important for computing time spent in app
	MK_AppExit(); //Let's MarkedUp know that the app is exiting
	stop = scanf_s("Hit enter\r\n");
	MK_Unload(); //Unloads the MarkedUp SDK dlls
	free(Items);

	stop = scanf_s("Hit enter again");

}

