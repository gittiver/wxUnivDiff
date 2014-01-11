#include <wx/docview.h>
#include <wx/cmdproc.h>
#include <wx/menu.h>
#include <wx/image.h>



#include "wxUnivDiffApp.hpp"

#include "MainFrame.h"

IMPLEMENT_APP(wxUnivDiffApp)

wxUnivDiffApp::wxUnivDiffApp(void) 
{}

wxUnivDiffApp::~wxUnivDiffApp(void)
{}

bool wxUnivDiffApp::OnInit(void)
{
  ::wxInitAllImageHandlers();

  if ( !wxApp::OnInit() )
    return false;
  
  // Create the main frame window
  MyFrame *frame = new MyFrame(wxT("wxListCtrl Test"));
  
  // Show the frame
  frame->Show(true);
  
  return true;
/*
	// start transaction
  //// Give it an icon (this is ignored in MDI mode: uses resources)
#ifdef __WXMSW__
  pMainframe->SetIcon(wxIcon(_T("doc")));
#endif
#ifdef __X__
  pMainframe->SetIcon(wxIcon(_T("doc.xbm")));
#endif

#ifdef __WXMAC__
  wxMenuBar::MacSetCommonMenuBar(pMainframe->GetMenuBar());
#endif //def __WXMAC__
  
  pMainframe->Centre(wxBOTH);

  SetTopWindow(pMainframe);
#ifndef __WXMAC__
  pMainframe->Show(true);
#endif //ndef __WXMAC__
	return true;
*/
}

void wxUnivDiffApp::info(const wxString& message)
{
  //Log entry(*pDatabase);
  //DateTime now;
  //entry.createdAt = now; 
  //entry.severity = Log::Severity::INFO;
  //entry.message= message.ToUTF8().data();
  //entry.update();
}

void wxUnivDiffApp::warn(const wxString& message)
{
  //Log entry(*pDatabase);
  //DateTime now;
  //entry.createdAt = now; 
  //entry.severity = Log::Severity::INFO;
  //entry.message = message.ToUTF8().data();
  //entry.update();
}

void wxUnivDiffApp::error(const wxString& message)
{
  //Log entry(*pDatabase);
  //DateTime now;
  //entry.createdAt = now; 
  //entry.severity = Log::Severity::INFO;
  //entry.message = message.ToUTF8().data();
  //entry.update();
}
