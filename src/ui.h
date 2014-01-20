///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
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
#include <wx/treectrl.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/listctrl.h>
#include <wx/splitter.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/toolbar.h>
#include <wx/frame.h>

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
	/// Class MainFrame2
	///////////////////////////////////////////////////////////////////////////////
	class MainFrame2 : public wxFrame 
	{
		private:
			wxTreeCtrl* m_treeCtrl1;
		
		protected:
			wxSplitterWindow* m_splitter1;
			wxPanel* m_panel1;
			wxPanel* m_panel2;
			wxNotebook* m_notebook1;
			wxSplitterWindow* m_splitter3;
			wxPanel* m_panel4;
			wxListCtrl* m_listCtrl1;
			wxMenuBar* m_menubar1;
			wxStatusBar* m_statusBar1;
			wxToolBar* m_toolBar1;
		
		public:
			
			MainFrame2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
			~MainFrame2();
			
			void m_splitter1OnIdle( wxIdleEvent& )
			{
				m_splitter1->SetSashPosition( 0 );
				m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame2::m_splitter1OnIdle ), NULL, this );
			}
			
			void m_splitter3OnIdle( wxIdleEvent& )
			{
				m_splitter3->SetSashPosition( 0 );
				m_splitter3->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame2::m_splitter3OnIdle ), NULL, this );
			}
		
	};
	
	///////////////////////////////////////////////////////////////////////////////
	/// Class MainFrame
	///////////////////////////////////////////////////////////////////////////////
	class MainFrame : public wxFrame 
	{
		private:
		
		protected:
			wxStatusBar* m_statusBar1;
			wxMenuBar* m_mainMenu;
			wxMenu* m_menuFile;
		
		public:
			
			MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
			~MainFrame();
		
	};
	
} // namespace ui

#endif //__ui__
