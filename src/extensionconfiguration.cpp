#include <wx/intl.h>
#include "wx/config.h"
#include "wx/hashmap.h"
#include "extensionconfiguration.hpp"


const char* const DEFAULT = _("extensions/default");

void ExtensionConfiguration::setExtension(const wxString& key,const wxString& executable_string,const wxString& parameters)
{
  extensions_executable_string[key] = executable_string;
  extensions_parameters[key] = parameters;
  //wxConfigBase* config= wxConfig::Get();
  //config->SetPath("/extensions");
  //config->Write(key,value);
  //config->Flush();
}

void ExtensionConfiguration::Write()
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

void ExtensionConfiguration::Load()
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
