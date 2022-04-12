//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: Creates a HTML control
//
// $NoKeywords: $
//=============================================================================//

#include "winlite.h"
#include "steam/steamtypes.h"
#include "tier1/interface.h"
#include "html/ihtmlserializer.h"
#include "html/ipainthtml.h"
#include "html/ihtmlchrome.h"
#include "html/ichromehtmlwrapper.h"

//-----------------------------------------------------------------------------
// Purpose: owner object that gets responses from the CEF thread and dispatches them
//-----------------------------------------------------------------------------

class CHTMLResponses : public IHTMLResponses
{
public:
 	void BrowserSetIndex( int idx )
	{

	}
 	int  BrowserGetIndex()
	{
        return 0;
	}
 	void BrowserReady( const CMsgBrowserReady *pCmd )
	{

	}
 	void BrowserNeedsPaint( const CMsgNeedsPaint *pCmd )
	{

	}
 	void BrowserStartRequest( const CMsgStartRequest *pCmd )
	{

	}
 	void BrowserURLChanged( const CMsgURLChanged *pCmd )
	{

	}
 	void BrowserFinishedRequest( const CMsgFinishedRequest *pCmd )
	{

	}
 	void BrowserShowPopup( const CMsgShowPopup *pCmd )
	{

	}
 	void BrowserHidePopup( const CMsgHidePopup *pCmd )
	{

	}
 	void BrowserOpenNewTab( const CMsgOpenNewTab *pCmd )
	{

	}
 	void BrowserPopupHTMLWindow( const CMsgPopupHTMLWindow *pCmd )
	{

	}
 	void BrowserSetHTMLTitle( const CMsgSetHTMLTitle *pCmd )
	{

	}
 	void BrowserLoadingResource( const CMsgLoadingResource *pCmd )
	{

	}
 	void BrowserStatusText( const CMsgStatusText *pCmd )
	{

	}
 	void BrowserSetCursor( const CMsgSetCursor *pCmd )
	{

	}
 	void BrowserFileLoadDialog( const CMsgFileLoadDialog *pCmd )
	{

	}
 	void BrowserShowToolTip( const CMsgShowToolTip *pCmd )
	{

	}
 	void BrowserUpdateToolTip( const CMsgUpdateToolTip *pCmd )
	{

	}
 	void BrowserHideToolTip( const CMsgHideToolTip *pCmd )
	{

	}
 	void BrowserSearchResults( const CMsgSearchResults *pCmd )
	{

	}
 	void BrowserClose( const CMsgClose *pCmd )
	{

	}
 	void BrowserHorizontalScrollBarSizeResponse( const CMsgHorizontalScrollBarSizeResponse *pCmd )
	{

	}
 	void BrowserVerticalScrollBarSizeResponse( const CMsgVerticalScrollBarSizeResponse *pCmd )
	{

	}
 	void BrowserGetZoomResponse( const CMsgGetZoomResponse *pCmd )
	{

	}
 	void BrowserLinkAtPositionResponse( const CMsgLinkAtPositionResponse *pCmd )
	{

	}
 	void BrowserZoomToElementAtPositionResponse( const CMsgZoomToElementAtPositionResponse *pCmd )
	{

	}
 	void BrowserJSAlert( const CMsgJSAlert *pCmd )
	{

	}
 	void BrowserJSConfirm( const CMsgJSConfirm *pCmd )
	{

	}
 	void BrowserCanGoBackandForward( const CMsgCanGoBackAndForward *pCmd )
	{

	}
 	void BrowserOpenSteamURL( const CMsgOpenSteamURL *pCmd )
	{

	}
 	void BrowserSizePopup( const CMsgSizePopup *pCmd )
	{

	}
 	void BrowserScalePageToValueResponse( const CMsgScalePageToValueResponse *pCmd )
	{

	}
 	void BrowserRequestFullScreen( const CMsgRequestFullScreen *pCmd )
	{

	}
 	void BrowserExitFullScreen( const CMsgExitFullScreen *pCmd )
	{

	}
 	void BrowserGetCookiesForURLResponse( const CMsgGetCookiesForURLResponse *pCmd )
	{

	}
 	void BrowserNodeGotFocus( const CMsgNodeHasFocus *pCmd )
	{

	}
 	void BrowserSavePageToJPEGResponse( const CMsgSavePageToJPEGResponse *pCmd )
	{

	}
 	void BrowserFocusedNodeValueResponse( const CMsgFocusedNodeTextResponse *pCmd )
	{

	}
};

static CHTMLResponses* g_HTMLResponses;

class CHTMLResponses_HL1  : public IHTMLResponses_HL1
{
public:
 	void BrowserReady()
	{

	}
 	void BrowserNeedsPaint( int textureid, 
									int wide, int tall, const unsigned char* rgba, 
									int updatex, int updatey, int updatewide, int updatetall, 
									int combobox_wide, int combobox_tall, const unsigned char* combobox_rgba )
	{

	}
 	void BrowserStartRequest( const char *url, const char *target, const char *postdata, bool isredirect )
	{

	}
 	void BrowserURLChanged( const char *url, const char *postdata, bool isredirect )
	{

	}
 	void BrowserFinishedRequest( const char *url, const char *pagetitle )
	{

	}
 	void BrowserShowPopup()
	{

	}
 	void BrowserHidePopup()
	{

	}
 	void BrowserSizePopup( int x, int y, int wide, int tall )
	{

	}
 	void BrowserHorizontalScrollBarSizeResponse( int x, int y, int wide, int tall, int scroll, int scroll_max, float zoom )
	{

	}
 	void BrowserVerticalScrollBarSizeResponse( int x, int y, int wide, int tall, int scroll, int scroll_max, float zoom )
	{

	}
 	void BrowserGetZoomResponse( float flZoom )
	{

	}
 	void BrowserCanGoBackandForward( bool bgoback, bool bgoforward )
	{

	}
 	void BrowserJSAlert( const char *message )
	{

	}
 	void BrowserJSConfirm( const char *message )
	{

	}
 	void BrowserPopupHTMLWindow( const char *url, int wide, int tall, int x, int y )
	{

	}
 	void BrowserSetHTMLTitle( const char *title )
	{

	}
 	void BrowserLoadingResource()
	{

	}
 	void BrowserStatusText( const char *text )
	{

	}
 	void BrowserSetCursor( int in_cursor )
	{

	}
 	void BrowserFileLoadDialog()
	{

	}
 	void BrowserShowToolTip( const char *text )
	{

	}
 	void BrowserUpdateToolTip( const char *text )
	{

	}
 	void BrowserHideToolTip()
	{

	}
 	void BrowserClose()
	{

	}
 	void BrowserLinkAtPositionResponse( const char *url, int x, int y )
	{

	}
};

static CHTMLResponses_HL1* g_HTMLResponses_HL1;

class CHTMLSerializer : public IHTMLSerializer 
{
public:
	IHTMLResponses* GetResponseTarget() 
	{
        return g_HTMLResponses;
	}
	int BrowserGetIndex() 
	{
        return 0;
	}
	void BrowserPosition( int x, int y ) 
	{

	}

	void PostURL( const char *pchURL, const char *pchPostData ) 
	{

	}
	void BrowserErrorStrings( const char *pchTitle, const char *pchHeader, const char *pchDetailCacheMiss, const char *pchDetailBadUURL, const char *pchDetailConnectionProblem, const char *pchDetailProxyProblem, const char *pchDetailUnknown ) 
	{

	}
	void StopLoad() 
	{

	}
	void Reload() 
	{

	}
	void GoBack() 
	{

	}
	void GoForward() 
	{

	}
	void MouseDown( int code ) 
	{

	}
	void MouseUp( int code ) 
	{

	}
	void MouseWheel( int delta ) 
	{

	}
	void MouseMove( int x, int y ) 
	{

	}
	void MouseDoubleClick( int code ) 
	{

	}
	void BrowserSize( int wide, int tall ) 
	{

	}
	void KeyUp( int key, int mods ) 
	{

	}
	void KeyDown( int key, int mods ) 
	{

	}
	void KeyChar( int unichar ) 
	{

	}
	void RunJavaScript( const char *pchScript ) 
	{

	}
	void SetHorizontalScroll( int scroll ) 
	{

	}
	void SetVerticalScroll( int scroll ) 
	{

	}
	void SetFocus( bool focus ) 
	{

	}
	void AddHeader( const char *pchHeader, const char *pchValue ) 
	{

	}
	void NeedsPaintResponse( int tex ) 
	{

	}
	void StartRequestResponse( bool bRes ) 
	{

	}
	void RequestBrowserSizes() 
	{

	}
	void JSDialogResponse( int res ) 
	{

	}
	void GetLinkAtPosition( int x, int y ) 
	{

	}
};

static CHTMLSerializer g_HTMLSerializer;

HTMLCommandBuffer_t *SGetFreeCommandBuffer( EHTMLCommands eCmd, int iBrowser )
{
	HTMLCommandBuffer_t *pBuf;

	pBuf->m_eCmd = eCmd;
	pBuf->m_iBrowser = iBrowser;
	return pBuf;
}

class CHTMLController : public IHTMLChromeController
{
public:
	CHTMLController() 
    { 

    }
	~CHTMLController() {}

	bool Init( const char *pchHTMLCacheDir, const char *pchCookiePath );
	void Shutdown();

	void SetWebCookie( const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath, RTime32 nExpires );
	void GetWebCookiesForURL( CUtlString *pstrValue, const char *pchURL, const char *pchName );
	void SetClientBuildID( uint64 ulBuildID );

	bool BHasPendingMessages();

	void CreateBrowser( IHTMLResponses *pBrowser, bool bPopupWindow, const char *pchUserAgentIdentifier );
	void RemoveBrowser( IHTMLResponses *pBrowser );
	bool RunFrame();

	void WakeThread() { }
	HTMLCommandBuffer_t *GetFreeCommandBuffer( EHTMLCommands eCmd, int iBrowser ) { return SGetFreeCommandBuffer(eCmd,iBrowser); }
	void PushCommand( HTMLCommandBuffer_t *pCmd ) {  }


	bool GetMainThreadCommand( HTMLCommandBuffer_t **pCmd ) { return false;  }
	void ReleaseCommandBuffer( HTMLCommandBuffer_t *pCmd ) {  }

#ifdef DBGFLAG_VALIDATE
	void Validate( CValidator &validator, const char *pchName );
	bool ChromePrepareForValidate();
	bool ChromeResumeFromValidate();
#endif
	
	void SetCefThreadTargetFrameRate( uint32 nFPS );

	IHTMLSerializer* CreateSerializer( IHTMLResponses_HL1* pResponseTarget ) { return &g_HTMLSerializer; };

private:

};


static CHTMLController s_HTMLController;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR( CHTMLController, IHTMLChromeController, CHROMEHTML_CONTROLLER_INTERFACE_VERSION, s_HTMLController );


//-----------------------------------------------------------------------------
// Purpose: request the cef thread to make a new browser
//-----------------------------------------------------------------------------
void CHTMLController::CreateBrowser( IHTMLResponses *pBrowser, bool bPopupWindow, const char *pchUserAgentIdentifier )
{
	Msg("CHTMLController::CreateBrowser");
}


//-----------------------------------------------------------------------------
// Purpose: delete a browser we have
//-----------------------------------------------------------------------------
void CHTMLController::RemoveBrowser( IHTMLResponses *pBrowser )
{
	Msg("CHTMLController::RemoveBrowser");
}


//-----------------------------------------------------------------------------
// Purpose: turn on the cef engine
//-----------------------------------------------------------------------------
bool CHTMLController::Init( const char *pchHTMLCacheDir, const char *pchCookiePath )
{
	return false;
}


//-----------------------------------------------------------------------------
// Purpose: shutdown chrome
//-----------------------------------------------------------------------------
void CHTMLController::Shutdown()
{
	Msg("CHTMLController::Shutdown");
}



//-----------------------------------------------------------------------------
// Purpose: process any ipc responses we have pending
//-----------------------------------------------------------------------------
bool CHTMLController::RunFrame()
{
	return false;
}

//-----------------------------------------------------------------------------
// Purpose: set a cef cookie
//-----------------------------------------------------------------------------
void CHTMLController::SetWebCookie( const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath, RTime32 nExpires )
{
	Msg("CHTMLController::SetWebCookie");
}


//-----------------------------------------------------------------------------
// Purpose: set the buildid to report
//-----------------------------------------------------------------------------
void CHTMLController::SetClientBuildID( uint64 ulBuildID )
{
	Msg("CHTMLController::SetClientBuildID");
}


//-----------------------------------------------------------------------------
// Purpose: get the cef cookies for a url
//-----------------------------------------------------------------------------
void CHTMLController::GetWebCookiesForURL( CUtlString *pstrValue, const char *pchURL, const char *pchName )
{
	Msg("CHTMLController::GetWebCookiesForURL");
}


//-----------------------------------------------------------------------------
// Purpose: true if any pending html message in the queue
//-----------------------------------------------------------------------------
bool CHTMLController::BHasPendingMessages()
{
	Msg("CHTMLController::BHasPendingMessages");

	return false;
}


//-----------------------------------------------------------------------------
// Purpose: tell the cef thread the frame rate to use if it changes
//-----------------------------------------------------------------------------
void CHTMLController::SetCefThreadTargetFrameRate( uint32 nFPS )
{
	Msg("CHTMLController::SetCefThreadTargetFrameRate");

}

#ifdef DBGFLAG_VALIDATE
//-----------------------------------------------------------------------------
// Purpose: validate mem
//-----------------------------------------------------------------------------
void CHTMLController::Validate( CValidator &validator, const char *pchName )
{

}

bool CHTMLController::ChromeResumeFromValidate()
{
	return false;
}

bool CHTMLController::ChromePrepareForValidate()
{
	return false;
}

#endif	// DBGFLAG_VALIDATE


