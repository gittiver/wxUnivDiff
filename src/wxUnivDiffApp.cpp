#include <wx/docview.h>
#include <wx/cmdproc.h>
#include <wx/menu.h>
#include <wx/image.h>
#include <wx/cmdline.h>
#include <wx/process.h>
#include <wx/stream.h>
#include <wx/msgdlg.h>
#include <list>
#include <set>

#include "wxUnivDiffApp.hpp"

#include "ui.h"
#include "cmdline.hpp"

#include "MimetypeListFrame.hpp"

using std::list;
using std::set;

IMPLEMENT_APP(wxUnivDiffApp)

wxUnivDiffApp::wxUnivDiffApp(void)
{}

wxUnivDiffApp::~wxUnivDiffApp(void)
{}

list<wxString> parameters;

set<wxString> getParameterFileExtensions()
{
  set<wxString> result;
  for(list<wxString>::const_iterator param = parameters.begin();
    param != parameters.end();
    param++
    )
  {
    wxFileName filename(*param);
    if (filename.HasExt()) 
    {
      result.insert(filename.GetExt());
    }
  }
  return result;
}

void wxUnivDiffApp::OnInitCmdLine(wxCmdLineParser& parser)
{
  parser.SetDesc(getCmdlineEntryDesc());
}

bool wxUnivDiffApp::OnCmdLineParsed	(	wxCmdLineParser & 	parser	)
{
  options_t& options = getOptions(); 
  options.verbose = parser.FoundSwitch("v")==wxCMD_SWITCH_ON;

  options.list = parser.FoundSwitch("l")==wxCMD_SWITCH_ON;
  options.add  = parser.FoundSwitch("a")==wxCMD_SWITCH_ON;
  options.del  = parser.FoundSwitch("del")==wxCMD_SWITCH_ON;
  options.interactive = parser.FoundSwitch("i")==wxCMD_SWITCH_ON || parser.GetParamCount()<2;
  options.diff = !(options.list||options.add||options.del||options.interactive);

  //Parse commandline parameters which are not switches
  for (wxCmdLineArgs::const_iterator itarg=parser.GetArguments().begin();
                                   itarg!=parser.GetArguments().end();
                                   ++itarg)
  {
    wxString optionName;
    switch (itarg->GetKind())
    {
    case wxCMD_LINE_PARAM:
        parameters.push_back(itarg->GetStrVal());
        break;
    default:
      // do nothing for other than (string) parameters
      break;
    }
  }

  return true;
}

wxStringToStringHashMap extensions_executable_string;
wxStringToStringHashMap extensions_parameters;

const char* const DEFAULT = _("extensions/default");

void setExtension(const wxString& key,const wxString& executable_string,const wxString& parameters)
{
  extensions_executable_string[key] = executable_string;
  extensions_parameters[key] = parameters;
  //wxConfigBase* config= wxConfig::Get();
  //config->SetPath("/extensions");
  //config->Write(key,value);
  //config->Flush();

}

void WriteExtensions()
{
  wxConfigBase* config= wxConfig::Get();
  wxString strOldPath;
  wxStringToStringHashMap::const_iterator parameters_it;

  config->SetPath("/extensions");
  for( wxStringToStringHashMap::const_iterator 
    it = extensions_executable_string.begin();
    it != extensions_executable_string.end();
  ++it
    )
  {
    strOldPath = config->GetPath();
    
    config->Write(it->first,_("executable"));
    config->SetPath(it->first);
    config->Write(_("executable"),it->second);
    
    parameters_it = extensions_parameters.find(it->first);
    if (parameters_it != extensions_parameters.end())
    {
      config->Write(_("parameters"),parameters_it->second);
    }
    
    config->SetPath(strOldPath);
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
    if (!value.IsSameAs(_("executable")))
    {
      // old format: extension = executable
      extensions_executable_string[str] = value;
    }
    else 
    {
      // TODO read new format
    }
    cont = config->GetNextEntry(str,lIndex);
  } while(cont);
}

bool wxUnivDiffApp::RunInteractive()
{
  MimeTypeListFrame* mimetypeListFrame = new MimeTypeListFrame;

  long index=0;
  wxListItem item;
  for (wxStringToStringHashMap::iterator it = extensions_executable_string.begin();
    it != extensions_executable_string.end();
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
  wxStringToStringHashMap::const_iterator cmd = extensions_executable_string.end(); 
  set<wxString> param_ext = getParameterFileExtensions();

  for(set<wxString>::const_iterator it_ext = param_ext.begin(); 
    it_ext != param_ext.end();
    it_ext++)
  {
    cmd = extensions_executable_string.find(*it_ext);
    if (cmd!=extensions_executable_string.end())
    {
      break;
    }
  }

  /* if no command is found, search for default command */
  if (cmd==extensions_executable_string.end())
  {
    cmd = extensions_executable_string.find("default");
  }

  if (cmd == extensions_executable_string.end())
  {
    //TODO error handling
  }
  else
  {
    wxString cmd(cmd->second);

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

  // TODO what should we do on EXIT_FAILURE ?
  return pRunProcess ? EXIT_SUCCESS : EXIT_FAILURE;
}

bool wxUnivDiffApp::OnInit(void)
{
  ::wxInitAllImageHandlers();

  if ( !wxApp::OnInit() )
    return false;

  LoadExtensions();
  if (!getOptions().diff)
    return RunInteractive();
  return true;
}

int wxUnivDiffApp::OnRun(void)
{
  // TODO check other flags
  if (getOptions().diff) {
    return RunCmdMode();
  } else {
    return wxApp::OnRun();
  }
}
