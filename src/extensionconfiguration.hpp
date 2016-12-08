#ifndef EXTENSIONCONFIGURATION_HPP
#define EXTENSIONCONFIGURATION_HPP

class ExtensionConfiguration {
public:
  void setExtension(const wxString& key,const wxString& executable_string,const wxString& parameters);

  void Write();
  void Load();
private:
  wxStringToStringHashMap extensions_executable_string;
  wxStringToStringHashMap extensions_parameters;
};

#endif // #ifndef EXTENSIONCONFIGURATION_HPP
