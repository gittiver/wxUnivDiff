#include <wx/intl.h>
#include <wx/config.h>

#include "extensionconfiguration.hpp"

const char* const DEFAULT = _("extensions/default");

void ExtensionConfiguration::setExtension(const wxString& key,const wxString& executable_string,const wxString& parameters)
{
  Entry entry = { executable_string, parameters };
  entries[key] = entry; 
  //wxConfigBase* config= wxConfig::Get();
  //config->SetPath("/extensions");
  //config->Write(key,value);
  //config->Flush();
}

/** return null if none found, else the found entry or defaultentry  */
const ExtensionConfiguration::Entry* const ExtensionConfiguration::getExtensionEntry(const wxString& key) const
{
  EntryMap::const_iterator it= entries.find(key);
  return (it == entries.end()) ? NULL : &(it->second);
}

const ExtensionConfiguration::EntryMap& ExtensionConfiguration::getEntries() const
{
  return entries;
} 

void ExtensionConfiguration::Write() const
{
  wxConfigBase* config= wxConfig::Get();
  wxString strOldPath;
  wxStringToStringHashMap::const_iterator parameters_it;

  config->SetPath("/extensions");

  for( EntryMap::const_iterator
      it = entries.begin();
      it != entries.end();
      ++it
      )
  {
    strOldPath = config->GetPath();

    config->Write(it->first,_("executable"));
    config->SetPath(it->first);
    config->Write(_("executable"),(it->second).executable_string);
    config->Write(_("parameters"),(it->second).parameters);

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
      entries[str].executable_string = value; 
    }
    else
    {
      // TODO read new format
    }
    cont = config->GetNextEntry(str,lIndex);
  } while(cont);
}
