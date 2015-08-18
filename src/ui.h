///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __ui__
#define __ui__

#include <wx/cshelp.h>
#include <wx/intl.h>

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/filepicker.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////

namespace ui
{
	///////////////////////////////////////////////////////////////////////////////
	/// Class AboutDialog
	///////////////////////////////////////////////////////////////////////////////
	class AboutDialog : public wxDialog 
	{
		private:
		
		protected:
			wxStaticText* m_staticText4;
			wxStaticText* m_staticText5;
			wxButton* m_btnClose;
		
		public:
			
			AboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 345,320 ), long style = wxDEFAULT_DIALOG_STYLE );
			~AboutDialog();
		
	};
	
	///////////////////////////////////////////////////////////////////////////////
	/// Class MimetypeListFrameBase
	///////////////////////////////////////////////////////////////////////////////
	class MimetypeListFrameBase : public wxFrame 
	{
		private:
		
		protected:
			wxPanel* m_panel5;
			wxStdDialogButtonSizer* m_sdbSizer1;
			wxButton* m_sdbSizer1OK;
			wxButton* m_sdbSizer1Apply;
			wxButton* m_sdbSizer1Cancel;
			wxButton* m_sdbSizer1Help;
			
			
			// Virtual event handlers, overide them in your derived class
			virtual void OnDelete( wxListEvent& event ) { event.Skip(); }
			virtual void OnEndEdit( wxListEvent& event ) { event.Skip(); }
			virtual void OnInsertItem( wxListEvent& event ) { event.Skip(); }
			virtual void OnListItemActivated( wxListEvent& event ) { event.Skip(); }
			virtual void OnApply( wxCommandEvent& event ) { event.Skip(); }
			virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
			virtual void OnHelp( wxCommandEvent& event ) { event.Skip(); }
			virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
			
		
		public:
			wxListCtrl* m_listCtrlMimetypes;
			
			MimetypeListFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 865,497 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
			~MimetypeListFrameBase();
		
	};
	
	///////////////////////////////////////////////////////////////////////////////
	/// Class EditEntryDialog
	///////////////////////////////////////////////////////////////////////////////
	class EditEntryDialog : public wxDialog 
	{
		private:
		
		protected:
			wxStaticText* m_staticTextCommand;
			wxStaticText* m_staticTextExtension;
			wxStdDialogButtonSizer* m_sdbSizer2;
			wxButton* m_sdbSizer2OK;
			wxButton* m_sdbSizer2Cancel;
			wxButton* m_sdbSizer2Help;
		
		public:
			wxFilePickerCtrl* m_filePickerCommand;
			wxTextCtrl* m_textCtrlExtension;
			
			EditEntryDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Entry"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 586,169 ), long style = wxDEFAULT_DIALOG_STYLE );
			~EditEntryDialog();
		
	};
	
} // namespace ui

#endif //__ui__
