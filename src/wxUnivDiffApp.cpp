#include <wx/docview.h>
#include <wx/cmdproc.h>
#include <wx/menu.h>
#include <wx/image.h>
#include <wx/cmdline.h>
#include <wx/process.h>
#include <wx/stream.h>
#include <wx/msgdlg.h>
#include <list>

#include "wxUnivDiffApp.hpp"

#include "ui.h"

using namespace ui;
using std::list;

static const wxCmdLineEntryDesc cmdLineDesc[] = {
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

IMPLEMENT_APP(wxUnivDiffApp)

  wxUnivDiffApp::wxUnivDiffApp(void)
{}

wxUnivDiffApp::~wxUnivDiffApp(void)
{}

struct options_t {
  bool verbose;
  bool list;
  bool add;
  bool del;
  bool interactive;
  bool diff;
} options = { false,false,false,false,false,false };

list<wxString> parameters;

void wxUnivDiffApp::OnInitCmdLine(wxCmdLineParser& parser)
{
  parser.SetDesc(cmdLineDesc);
}

bool isCmdLineSwitch(const wxString& param)
{
  for (size_t option_index=0;
    option_index < sizeof(cmdLineDesc)/sizeof(cmdLineDesc[0]);
    ++option_index)
  {
    if ( param.substr(1).StartsWith(cmdLineDesc[option_index].shortName ) ) {
      return true;
    }
  }
  return false;
}

bool wxUnivDiffApp::OnCmdLineParsed	(	wxCmdLineParser & 	parser	)
{
  options.verbose = parser.FoundSwitch("v")==wxCMD_SWITCH_ON;

  options.list = parser.FoundSwitch("l")==wxCMD_SWITCH_ON;
  options.add  = parser.FoundSwitch("a")==wxCMD_SWITCH_ON;
  options.del  = parser.FoundSwitch("del")==wxCMD_SWITCH_ON;
  options.interactive = parser.FoundSwitch("i")==wxCMD_SWITCH_ON || parser.GetParamCount()<2;
  options.diff = !(options.list||options.add||options.del||options.interactive);

  //Parse commandline parameters which are not switches
  wxString param;
  for (size_t i=0; i <parser.GetParamCount(); ++i) {
    param = parser.GetParam(i);
    if (!isCmdLineSwitch(param)) {
      parameters.push_back(param);
    }
  }
  return true;
}

using namespace ui;

wxStringToStringHashMap extensions;
const char* const DEFAULT = "extensions/default";

void setExtension(const wxString& key,const wxString& value)
{
  extensions[key] = value;

  //wxConfigBase* config= wxConfig::Get();
  //config->SetPath("/extensions");
  //config->Write(key,value);
  //config->Flush();

}

void WriteExtensions()
{
  wxConfigBase* config= wxConfig::Get();
  config->SetPath("/extensions");
  for( wxStringToStringHashMap::const_iterator 
    it = extensions.begin();
    it != extensions.end();
  ++it
    )
  {
    config->Write(it->first,it->second);
  }
  // TODO we have to delete entries not in extension list
}


void LoadExtensions()
{
  wxConfigBase* config= wxConfig::Get();

  if (!config->HasGroup(_("extensions")) ) 
  {
    config->Write("extensions/txt","self");
    config->Write("extensions/bin","selfbin");
#ifdef __APPLE__
    config->Write(DEFAULT,"/usr/bin/diffmerge.sh");
#elif defined( WIN32 )
    config->Write(DEFAULT, "C:\\Tools\\WinMerge\\WinMergeU.exe");
#else
    // TODO write default application config for other systems
#endif // #ifdef __APPLE__

    config->Flush();
  } 

  // TODO in any case there should be a default entry

  wxString str;
  long lIndex;
  wxString value;
  config->SetPath("/extensions");
  bool cont = config->GetFirstEntry(str, lIndex);
  do {
    config->Read(str,&value);
    extensions[str] = value;
    cont = config->GetNextEntry(str,lIndex);
  } while(cont);
}

bool wxUnivDiffApp::RunInteractive()
{
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
  class MimeTypeListFrame: public MimetypeListFrameBase
  {
  public:
    MimeTypeListFrame()
      : MimetypeListFrameBase(NULL,wxID_ANY,wxT("Verknuepfte Anwendungen")) {}

    void OnApply( wxCommandEvent& /*event*/ )
    {
      WriteExtensions();
    }
    void OnCancel( wxCommandEvent& /*event */)
    {
      Close();
    }
    void OnOk( wxCommandEvent& /*event*/ )
    {
      WriteExtensions();
      Close();
    }
    void OnHelp( wxCommandEvent& /*event*/ )
    {
      wxMessageBox(_T("Help"));
    }

    void OnListItemActivated( wxListEvent& event )
    {
      wxString key;
      wxFileName fname;
      int index = event.GetIndex();

      EditEntryDialog dlg(this);

      dlg.m_textCtrlExtension->SetValue(this->m_listCtrlMimetypes->GetItemText(index,0));
      fname = this->m_listCtrlMimetypes->GetItemText(index,1);
      dlg.m_filePickerCommand->SetFileName(fname);

      int result = dlg.ShowModal();
      if (result==wxID_OK)
      {
        key = dlg.m_textCtrlExtension->GetValue();
        fname = dlg.m_filePickerCommand->GetFileName(); 

        this->m_listCtrlMimetypes->SetItem(index, 0,key );
        this->m_listCtrlMimetypes->SetItem(index, 1,fname.GetFullPath() );
        setExtension(key,fname.GetFullPath());
      }
    }

  };

  MimetypeListFrameBase* mimetypeListFrame = new MimeTypeListFrame;

  mimetypeListFrame->m_listCtrlMimetypes->InsertColumn(1,"Extensions");
  mimetypeListFrame->m_listCtrlMimetypes->InsertColumn(2,"Aufruf");

  long index=0;
  wxListItem item;
  for (wxStringToStringHashMap::iterator it = extensions.begin();
    it != extensions.end();
    ++it) {
      item.SetText(it->first);
      item.SetColumn(0);
      item.SetId(index);
      index = mimetypeListFrame->m_listCtrlMimetypes->InsertItem( item );

      item.SetId(index);
      item.SetColumn(1);
      item.SetText(it->second);

      mimetypeListFrame->m_listCtrlMimetypes->SetItem(index, 1,it->second );
  }

  return mimetypeListFrame->Show(true);

  /*
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


wxProcess* pRunProcess;
int wxUnivDiffApp::RunCmdMode()
{
  wxStringToStringHashMap::const_iterator defaultCmd = extensions.find("default");
  if (defaultCmd == extensions.end())
  {
    //TODO error handling
  }
  else
  {
    wxString cmd(defaultCmd->second);

    // append parameters from commandline
    for (list<wxString>::const_iterator
      param = parameters.begin();
      param != parameters.end();
    ++param)
    {
      cmd.append(" ");
      cmd.append(*param);
    }

    // and run it ...
    pRunProcess = wxProcess::Open(cmd);
  }

  return pRunProcess ? EXIT_SUCCESS : EXIT_FAILURE;
}

bool wxUnivDiffApp::OnInit(void)
{
  ::wxInitAllImageHandlers();

  if ( !wxApp::OnInit() )
    return false;

  LoadExtensions();
  if (!options.diff)
    return RunInteractive();
  return true;
}

int wxUnivDiffApp::OnRun(void)
{
  // TODO check other flags
  if (options.diff) {
    return RunCmdMode();
  } else {
    return wxApp::OnRun();
  }
}



