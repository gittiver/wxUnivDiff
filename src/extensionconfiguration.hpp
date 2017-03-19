#ifndef EXTENSIONCONFIGURATION_HPP
#define EXTENSIONCONFIGURATION_HPP

#include <string>
#include <map>

class ExtensionConfiguration {
public:
  typedef struct Entry_t {
    wxString executable_string;
    wxString parameters;
  } Entry;
  
  typedef std::map<wxString,ExtensionConfiguration::Entry> EntryMap;

  void setExtension(const wxString& key,const wxString& executable_string,const wxString& parameters=_(""));
  const Entry* const getExtensionEntry(const wxString& key) const;
  
  const EntryMap& getEntries() const; 
  
  void Write() const;
  void Load();

  private:
    EntryMap entries;
};

#endif // #ifndef EXTENSIONCONFIGURATION_HPP
