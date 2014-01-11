#ifndef wxUnivDiffApp_hpp
#define wxUnivDiffApp_hpp

#include <wx/app.h>

class wxUnivDiffApp : public wxApp
{
public:
  enum {
        ID_GENERATE = wxID_HIGHEST+1,

        ID_ABOUT 
        };
    wxUnivDiffApp(void);
    virtual ~wxUnivDiffApp(void);

    void info(const wxString& message);
    void warn(const wxString& message);
    void error(const wxString& message);

protected:
	bool OnInit(void);
};

DECLARE_APP(wxUnivDiffApp)

#endif // #ifndef wxUnivDiffApp_hpp
