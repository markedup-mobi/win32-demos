#ifdef MARKEDUPWIN32_EXPORTS
#define DECLSPEC_M __declspec(dllexport)
#else
#define DECLSPEC_M __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WCHAR //Define WCHAR as a 2-byte character in the event that the environment doesn't support it
	typedef wchar_t WCHAR;
#endif

	/* Structures used throughout various MarkedUp Analytics methods - used for capturing exceptions, purchases, and application state */

	//Exception object with ANSI strings 
	typedef struct  MK_ExceptionA {
		const char* ErrorMessage;
		const char* StackTrace;
		const char* ExceptionType;
		const char* ErrorCode;
	} _mkea;

	//Tuple object with ANSI strings - used with parameter dictonaries
	typedef struct  MK_TupleA {
		const char* Key;
		const char* Value;
	} _mkta;

	//Parameter dictionary object with ANSI Tuple classes - used to populate event / log message properties
	typedef struct MK_ParamDictionaryA {
		const _mkta* Items;
		int ItemCount;
	} _mkpa;

	//Exception object with Unicode (UTF-16) strings
	typedef struct MK_ExceptionW {
		const WCHAR* ErrorMessage;
		const WCHAR* StackTrace;
		const WCHAR* ExceptionType;
		const WCHAR* ErrorCode;
	} _mkew;

	//Tuple object with Unicode (UTF-16) strings - used with parameter dictonaries
	typedef struct MK_TupleW {
		const WCHAR* Key;
		const WCHAR* Value;
	} _mktw;

	//Parameter dictionary object with Unicode Tuple classes - used to populate event / log message properties
	typedef struct MK_ParamDictionaryW {
		const _mktw* Items;
		int ItemCount;
	} _mkpw;

	/// <summary>
	/// Class that represents an in-app purchase - designed to be used
	/// with the InAppPurchaseCompleted event (UNICODE)
	/// </summary>
	typedef struct MK_InAppPurchaseW{
		/// <summary>
		/// [REQUIRED] The unique identifier for this product.
		/// 
		/// For TrialConversion events, this defaults to the ID for this app if left blank.
		/// </summary>
		const WCHAR* ProductId;

		/// <summary>
		/// [REQUIRED] The human-readable name for this product.
		/// 
		/// For TrialConversion events, this defaults to the name for this app if left blank.
		/// </summary>
		const WCHAR* ProductName;

		/// <summary>
		/// The Currency that this transaction is using (i.e. "USD" for US Dollars, "EUR" for Euros, etc...)
		/// 
		/// If this field is left blank the value will be populated using the user's default region and currency settings.
		/// </summary>
		const WCHAR* Currency;

		/// <summary>
		/// The price of this in-app purchase in the <Currency/> specified.
		/// 
		/// Defaults to 0.00!
		/// </summary>
		double Price;

		/// <summary>
		/// The current market for this user (i.e. "US" for United States, "CA" for Canada, etc...)
		/// 
		/// If left blank, this value will be automatically populated with the user's current region settings
		/// </summary>
		const WCHAR* CurrentMarket;

		/// <summary>
		/// The name of the commerce engine being used. If you're using the Windows Store, leave this value blank.
		/// 
		/// Otherwise, if you're using PayPal, Amazon Payments, or any other custom commerce system please
		/// specify that value here.
		/// </summary>
		const WCHAR* CommerceEngine;
	} _iapw;

	/// <summary>
	/// Class that represents an in-app purchase - designed to be used
	/// with the InAppPurchaseCompleted event (ANSI)
	/// </summary>
	typedef struct MK_InAppPurchaseA{
		/// <summary>
		/// [REQUIRED] The unique identifier for this product.
		/// 
		/// For TrialConversion events, this defaults to the ID for this app if left blank.
		/// </summary>
		const char* ProductId;

		/// <summary>
		/// [REQUIRED] The human-readable name for this product.
		/// 
		/// For TrialConversion events, this defaults to the name for this app if left blank.
		/// </summary>
		const char* ProductName;

		/// <summary>
		/// The Currency that this transaction is using (i.e. "USD" for US Dollars, "EUR" for Euros, etc...)
		/// 
		/// If this field is left blank the value will be populated using the user's default region and currency settings.
		/// </summary>
		const char* Currency;

		/// <summary>
		/// The price of this in-app purchase in the <Currency/> specified.
		/// 
		/// Defaults to 0.00!
		/// </summary>
		double Price;

		/// <summary>
		/// The current market for this user (i.e. "US" for United States, "CA" for Canada, etc...)
		/// 
		/// If left blank, this value will be automatically populated with the user's current region settings
		/// </summary>
		const char* CurrentMarket;

		/// <summary>
		/// The name of the commerce engine being used. If you're using the Windows Store, leave this value blank.
		/// 
		/// Otherwise, if you're using PayPal, Amazon Payments, or any other custom commerce system please
		/// specify that value here.
		/// </summary>
		const char* CommerceEngine;
	} _iapa;

	/* Initializers */
	/// <summary>
	/// Initialize MarkedUp SDK with a <b>single</b> API key and registry area using <b>ANSI</b> strings.
	/// <b>Note: this will load the MarkedUp .NET interop DLL if it hasn't been loaded already</b>
	///</summary>
	DECLSPEC_M void __cdecl MK_InitializeA(const char* apiKey, const char* registryArea);

	/// <summary>
	/// Initialize MarkedUp SDK with a <b>multiple</b> API keys and registry area using <b>ANSI</b> strings.
	/// <b>Note: this will load the MarkedUp .NET interop DLL if it hasn't been loaded already</b>
	///</summary>
	DECLSPEC_M void __cdecl MK_InitializeMA(const char* apiKeys [], const char* registryArea);

	/// <summary>
	/// Initialize MarkedUp SDK with a <b>single</b> API key and registry area using <b>UNICODE</b> strings.
	/// <b>Note: this will load the MarkedUp .NET interop DLL if it hasn't been loaded already</b>
	///</summary>
	DECLSPEC_M void __cdecl MK_InitializeW(const WCHAR* apiKey, const WCHAR* registryArea);

	/// <summary>
	/// Initialize MarkedUp SDK with a <b>multiple</b> API keys and registry area using <b>UNICODE</b> strings.
	/// <b>Note: this will load the MarkedUp .NET interop DLL if it hasn't been loaded already</b>
	///</summary>
	DECLSPEC_M void __cdecl MK_InitializeMW(const WCHAR* apiKeys [], const WCHAR* registryArea);

	/* Logging Methods */

	DECLSPEC_M void __cdecl MK_TraceA(const char* message);
	DECLSPEC_M void __cdecl MK_InfoA(const char* message);
	DECLSPEC_M void __cdecl MK_DebugA(const char* message);
	DECLSPEC_M void __cdecl MK_ErrorA(const char* message);
	DECLSPEC_M void __cdecl MK_FatalA(const char* message);

	DECLSPEC_M void __cdecl MK_TraceEA(const char* message, _mkea* ex);
	DECLSPEC_M void __cdecl MK_InfoEA(const char* message, _mkea* ex);
	DECLSPEC_M void __cdecl MK_DebugEA(const char* message, _mkea* ex);
	DECLSPEC_M void __cdecl MK_ErrorEA(const char* message, _mkea* ex);
	DECLSPEC_M void __cdecl MK_FatalEA(const char* message, _mkea* ex);

	DECLSPEC_M void __cdecl MK_TracePA(const char* message, _mkpa* state);
	DECLSPEC_M void __cdecl MK_InfoPA(const char* message, _mkpa* state);
	DECLSPEC_M void __cdecl MK_DebugPA(const char* message, _mkpa* state);
	DECLSPEC_M void __cdecl MK_ErrorPA(const char* message, _mkpa* state);
	DECLSPEC_M void __cdecl MK_FatalPA(const char* message, _mkpa* state);

	DECLSPEC_M void __cdecl MK_TraceEPA(const char* message, _mkea* ex, _mkpa* state);
	DECLSPEC_M void __cdecl MK_InfoEPA(const char* message, _mkea* ex, _mkpa* state);
	DECLSPEC_M void __cdecl MK_DebugEPA(const char* message, _mkea* ex, _mkpa* state);
	DECLSPEC_M void __cdecl MK_ErrorEPA(const char* message, _mkea* ex, _mkpa* state);
	DECLSPEC_M void __cdecl MK_FatalEPA(const char* message, _mkea* ex, _mkpa* state);

	DECLSPEC_M void __cdecl MK_TraceW(const WCHAR* message);
	DECLSPEC_M void __cdecl MK_InfoW(const WCHAR* message);
	DECLSPEC_M void __cdecl MK_DebugW(const WCHAR* message);
	DECLSPEC_M void __cdecl MK_ErrorW(const WCHAR* message);
	DECLSPEC_M void __cdecl MK_FatalW(const WCHAR* message);

	DECLSPEC_M void __cdecl MK_TraceEW(const WCHAR* message, _mkew* ex);
	DECLSPEC_M void __cdecl MK_InfoEW(const WCHAR* message, _mkew* ex);
	DECLSPEC_M void __cdecl MK_DebugEW(const WCHAR* message, _mkew* ex);
	DECLSPEC_M void __cdecl MK_ErrorEW(const WCHAR* message, _mkew* ex);
	DECLSPEC_M void __cdecl MK_FatalEW(const WCHAR* message, _mkew* ex);

	DECLSPEC_M void __cdecl MK_TracePW(const WCHAR* message, _mkpw* state);
	DECLSPEC_M void __cdecl MK_InfoPW(const WCHAR* message, _mkpw* state);
	DECLSPEC_M void __cdecl MK_DebugPW(const WCHAR* message, _mkpw* state);
	DECLSPEC_M void __cdecl MK_ErrorPW(const WCHAR* message, _mkpw* state);
	DECLSPEC_M void __cdecl MK_FatalPW(const WCHAR* message, _mkpw* state);

	DECLSPEC_M void __cdecl MK_TraceEPW(const WCHAR* message, _mkew* ex, _mkpw* state);
	DECLSPEC_M void __cdecl MK_InfoEPW(const WCHAR* message, _mkew* ex, _mkpw* state);
	DECLSPEC_M void __cdecl MK_DebugEPW(const WCHAR* message, _mkew* ex, _mkpw* state);
	DECLSPEC_M void __cdecl MK_ErrorEPW(const WCHAR* message, _mkew* ex, _mkpw* state);
	DECLSPEC_M void __cdecl MK_FatalEPW(const WCHAR* message, _mkew* ex, _mkpw* state);

	//Session Events
	DECLSPEC_M void __cdecl MK_SessionEventA(const char* eventName);
	DECLSPEC_M void __cdecl MK_SessionEventPA(const char* eventName, _mkpa* state);

	DECLSPEC_M void __cdecl MK_SessionEventW(const WCHAR* eventName);
	DECLSPEC_M void __cdecl MK_SessionEventPW(const WCHAR* eventName, _mkpw* state);

	//App lifecycle
	DECLSPEC_M void __cdecl MK_AppStart();
	DECLSPEC_M void __cdecl MK_AppSuspend();
	DECLSPEC_M void __cdecl MK_AppResume();
	DECLSPEC_M void __cdecl MK_AppExit();

	//Sessions
	DECLSPEC_M void __cdecl MK_SessionStart();
	DECLSPEC_M void __cdecl MK_SessionEnd();

	//Navigation Events
	DECLSPEC_M void __cdecl MK_EnterPageA(const char* pageName);
	DECLSPEC_M void __cdecl MK_ExitPageA(const char* pageName);
	DECLSPEC_M void __cdecl MK_EnterPageW(const WCHAR* pageName);
	DECLSPEC_M void __cdecl MK_ExitPageW(const WCHAR* pageName);

	//Commerce
	DECLSPEC_M void __cdecl MK_InAppPurchaseCompleteA(_iapa* iap);
	DECLSPEC_M void __cdecl MK_InAppPurchaseCompleteW(_iapw* iap);
	DECLSPEC_M void __cdecl MK_TrialConversionCompleteA(_iapa* tc);
	DECLSPEC_M void __cdecl MK_TrialConversionCompleteW(_iapw* tc);

	//OptOut
	DECLSPEC_M void __cdecl MK_OptOut(int optOutPreference);


	//Destructor
	DECLSPEC_M void __cdecl MK_Unload();

	/* Convenience Macros */
#if UNICODE //If the C++ compiler's UNICODE flag is enabled, these macros will automatically default to their UTF-16 implementations
	typedef _mktw MK_Tuple;
	typedef _mkew MK_Exception;
	typedef _mkpw MK_ParamDictionary;
	typedef _iapw MK_InAppPurchase;
#define MK_Initialize(apiKey, registryArea) MK_InitializeW(apiKey, registryArea);
#define MK_Initialize_Multiple(apiKeys, registryArea) MK_InitializeMW(apiKeys, registryArea);
#define MK_Trace(message) MK_TraceW(message);
#define MK_Trace_State(message, state) MK_TracePW(message, state);
#define MK_Trace_Exception(message, ex) MK_TraceEW(messsage, ex);
#define MK_Trace_Exception_State(message, ex, state) MK_TraceEPW(messsage, ex, state);

#define MK_Info(message) MK_InfoW(message);
#define MK_Info_State(message, state) MK_InfoPW(message, state);
#define MK_Info_Exception(message, ex) MK_InfoEW(messsage, ex);
#define MK_Info_Exception_State(message, ex, state) MK_InfoEPW(messsage, ex, state);

#define MK_Debug(message) MK_DebugW(message);
#define MK_Debug_State(message, state) MK_DebugPW(message, state);
#define MK_Debug_Exception(message, ex) MK_DebugEW(messsage, ex);
#define MK_Debug_Exception_State(message, ex, state) MK_DebugEPW(messsage, ex, state);

#define MK_Error(message) MK_ErrorW(message);
#define MK_Error_State(message, state) MK_ErrorPW(message, state);
#define MK_Error_Exception(message, ex) MK_ErrorEW(messsage, ex);
#define MK_Error_Exception_State(message, ex, state) MK_ErrorEPW(messsage, ex, state);

#define MK_Fatal(message) MK_FatalW(message);
#define MK_Fatal_State(message, state) MK_FatalPW(message, state);
#define MK_Fatal_Exception(message, ex) MK_FatalEW(messsage, ex);
#define MK_Fatal_Exception_State(message, ex, state) MK_FatalEPW(messsage, ex, state);

#define MK_SessionEvent(eventName) MK_SessionEventW(eventName);
#define MK_SessionEvent_State(eventName, state) MK_SessionEventPW(eventName, state);

#define MK_EnterPage(pageName) MK_EnterPageW(pageName);
#define MK_ExitPage(pageName) MK_ExitPageW(pageName);

#define MK_InAppPurchaseComplete(iap) MK_InAppPurchaseCompleteW(iap);
#define MK_TrialConversionComplete(tc) MK_TrialConversionCompleteW(tc);
#else //If the C++ compiler is not operating with UNICODE, all macros default to ANSI implementations
	typedef _mkta MK_Tuple;
	typedef _mkea MK_Exception;
	typedef _mkpa MK_ParamDictionary;
	typedef _iapa MK_InAppPurchase;

#define MK_Initialize(apiKey, registryArea) MK_InitializeA(apiKey, registryArea);
#define MK_Initialize_Multiple(apiKeys, registryArea) MK_InitializeMA(apiKeys, registryArea);
#define MK_Trace(message) MK_TraceA(message);
#define MK_Trace_State(message, state) MK_TracePA(message, state);
#define MK_Trace_Exception(message, ex) MK_TraceEA(messsage, ex);
#define MK_Trace_Exception_State(message, ex, state) MK_TraceEPA(messsage, ex, state);

#define MK_Info(message) MK_InfoA(message);
#define MK_Info_State(message, state) MK_InfoPA(message, state);
#define MK_Info_Exception(message, ex) MK_InfoEA(messsage, ex);
#define MK_Info_Exception_State(message, ex, state) MK_InfoEPA(messsage, ex, state);

#define MK_Debug(message) MK_DebugA(message);
#define MK_Debug_State(message, state) MK_DebugPA(message, state);
#define MK_Debug_Exception(message, ex) MK_DebugEA(messsage, ex);
#define MK_Debug_Exception_State(message, ex, state) MK_DebugEPA(messsage, ex, state);

#define MK_Error(message) MK_ErrorA(message);
#define MK_Error_State(message, state) MK_ErrorPA(message, state);
#define MK_Error_Exception(message, ex) MK_ErrorEA(messsage, ex);
#define MK_Error_Exception_State(message, ex, state) MK_ErrorEPA(messsage, ex, state);

#define MK_Fatal(message) MK_FatalA(message);
#define MK_Fatal_State(message, state) MK_FatalPA(message, state);
#define MK_Fatal_Exception(message, ex) MK_FatalEA(messsage, ex);
#define MK_Fatal_Exception_State(message, ex, state) MK_FatalEPA(messsage, ex, state);

#define MK_SessionEvent(eventName) MK_SessionEventA(eventName);
#define MK_SessionEvent_State(eventName, state) MK_SessionEventPA(eventName, state);
#define MK_EnterPage(pageName) MK_EnterPageA(pageName);
#define MK_ExitPage(pageName) MK_ExitPageA(pageName);

#define MK_InAppPurchaseComplete(iap) MK_InAppPurchaseCompleteA(iap);
#define MK_TrialConversionComplete(tc) MK_TrialConversionCompleteA(tc);
#endif

#ifdef __cplusplus
}
#endif