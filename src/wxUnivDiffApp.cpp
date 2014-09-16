#include <wx/docview.h>
#include <wx/cmdproc.h>
#include <wx/menu.h>
#include <wx/image.h>
#include <wx/cmdline.h>
#include <wx/process.h>
#include <wx/stream.h>

#include "wxUnivDiffApp.hpp"

//#include "MainFrame.h"
#include "ui.h"

IMPLEMENT_APP(wxUnivDiffApp)

wxUnivDiffApp::wxUnivDiffApp(void) 
{}

wxUnivDiffApp::~wxUnivDiffApp(void)
{}

static const wxCmdLineEntryDesc cmdLineDesc[] =
{
  { wxCMD_LINE_SWITCH, "v", "verbose", "be verbose" },
  //{ wxCMD_LINE_SWITCH, "q", "quiet",   "be quiet" },
  
  // { wxCMD_LINE_OPTION, "o", "output",  "output file" },
  { wxCMD_LINE_OPTION, "i", "interactive",   "interactive mode" },
  
  { wxCMD_LINE_OPTION, "l", "list",   "list " },
  { wxCMD_LINE_OPTION, "a", "add",   "add entry" },
  { wxCMD_LINE_OPTION, "del", "del",   "del entry" },
  
  
  { wxCMD_LINE_PARAM,  NULL, NULL, "input file", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_MULTIPLE| wxCMD_LINE_PARAM_OPTIONAL },
  
  { wxCMD_LINE_NONE }
};

enum {
  INTERACTIVE,
  LIST,
  ADD,
  DEL,
  EDIT,
  DIFF
} mode;

bool verbose;
bool list;
bool add;
bool del;

void wxUnivDiffApp::OnInitCmdLine(wxCmdLineParser& parser)
{
   parser.SetDesc(cmdLineDesc);
}

bool wxUnivDiffApp::OnCmdLineParsed	(	wxCmdLineParser & 	parser	)
{
   verbose = parser.FoundSwitch("v")==wxCMD_SWITCH_ON;
   if (parser.FoundSwitch("i")==wxCMD_SWITCH_ON)
      mode = INTERACTIVE;

   parser.FoundSwitch("l")==wxCMD_SWITCH_ON;
   parser.FoundSwitch("a")==wxCMD_SWITCH_ON;
   parser.FoundSwitch("del")==wxCMD_SWITCH_ON;


  size_t c = parser.GetParamCount();
  if (c>1)
  {
    mode = DIFF;
  }
  else
  {
    mode = INTERACTIVE;
  }
  return true;
}

class Pp : public wxProcess {
public:
  virtual void OnTerminate(int pid, int status)
  {
    wxLogDebug("x");
  }
};

Pp p;

using namespace ui;

bool wxUnivDiffApp::OnInit(void)
{
  ::wxInitAllImageHandlers();

  if ( !wxApp::OnInit() )
    return false;
  
//  wxArrayString r;
//  // long result = wxShell("echo abc; exit", r);
//  p.Redirect();
//  long  result =  wxExecute("date",wxEXEC_ASYNC,&p);
//  wxInputStream* in = p.GetInputStream();
//  
//  wxChar buf[1024];
//  while(in->CanRead())
//  {
//    in->ReadAll(buf,sizeof(buf));
//    wxLogDebug(buf);
//  };
  // Create the main frame window
  //MyFrame *frame = new MyFrame(wxT("wxListCtrl Test"));
  //MainFrame *frame = new MainFrame(NULL,wxID_ANY,wxT("tesme"));
  //// Show the frame
  //frame->Show(true);
  class MimeTypeListController {
  public:
     MimeTypeListController (MimetypeListFrame*
  };
  
  MimeTypeListController c;
  MimetypeListFrame* mimetypeListFrame = new MimetypeListFrame(NULL,wxID_ANY,wxT("Verknüpfte Anwendungen"));
  return mimetypeListFrame->Show(true);

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

