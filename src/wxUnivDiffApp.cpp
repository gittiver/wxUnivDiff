#include <wx/cmdproc.h>
#include <wx/menu.h>
#include <wx/image.h>
#include <wx/cmdline.h>
#include <wx/process.h>
#include <wx/msgdlg.h>
#include <list>
#include <set>

#include "wxUnivDiffApp.hpp"

#include "ui.h"
#include "cmdline.hpp"

#include "MimeTypeListFrame.hpp"
#include "extensionconfiguration.hpp"

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

ExtensionConfiguration  extensionConfiguration;

bool wxUnivDiffApp::RunInteractive() const
{
  MimeTypeListFrame* mimetypeListFrame = new MimeTypeListFrame(&extensionConfiguration);
  mimetypeListFrame->loadModel();

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
int wxUnivDiffApp::RunCmdMode() const
{
  //wxStringToStringHashMap::const_iterator cmd = extensionConfiguration.extensions_executable_string.end(); 
  set<wxString> param_ext = getParameterFileExtensions();
  
  const ExtensionConfiguration::Entry* pEntry = NULL;
  
  for(set<wxString>::const_iterator it_ext = param_ext.begin(); 
    it_ext != param_ext.end();
    it_ext++)
  {
    pEntry = extensionConfiguration.getExtensionEntry(*it_ext); 
    if (pEntry!=NULL)
    {
      break;
    }
  }

  /* if no command is found, search for default command */
  if (pEntry==NULL)
  {
    pEntry = extensionConfiguration.getExtensionEntry("default");
  }

  if (pEntry==NULL)
  {
    //TODO error handling
  }
  else
  {
    wxString command(pEntry->executable_string);

    // TODO add extension parameters and replace $1..$n with parameter values
    // append parameters from commandline
    for (list<wxString>::const_iterator
      param = parameters.begin();
      param != parameters.end();
    ++param)
    {
      command.append(" ");
      command.append(*param);
    }

    // and run it ...
    pRunProcess = wxProcess::Open(command);
  }

  // TODO what should we do on EXIT_FAILURE ?
  return pRunProcess ? EXIT_SUCCESS : EXIT_FAILURE;
}

bool wxUnivDiffApp::OnInit(void)
{
  ::wxInitAllImageHandlers();
  bool success = false;

  if ( !wxApp::OnInit() )
  {
  }
  else 
  {
    extensionConfiguration.Load();

    if (!getOptions().diff)
    {  
      success = RunInteractive();
    }
    else
    { 
      success = true;
    }
  }
  return success;
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
