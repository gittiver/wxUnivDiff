#ifndef wxUnivDiffApp_hpp
#define wxUnivDiffApp_hpp

#include <wx/app.h>
#include <wx/config.h>

class wxUnivDiffApp : public wxApp
{
public:
  enum {
        ID_GENERATE = wxID_HIGHEST+1,

        ID_ABOUT 
        };
    wxUnivDiffApp(void);
    virtual ~wxUnivDiffApp(void);
  
    virtual void OnInitCmdLine(wxCmdLineParser& parser);
    virtual bool OnCmdLineParsed	(	wxCmdLineParser & 	parser	);

protected:
	bool OnInit(void);
private:
  bool RunInteractive();
  bool RunCmdMode();

};

DECLARE_APP(wxUnivDiffApp)

#endif // #ifndef wxUnivDiffApp_hpp
