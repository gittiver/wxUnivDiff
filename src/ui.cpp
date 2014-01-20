///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ui.h"

// Using the construction of a static object to ensure that the help provider is set
class wxFBContextSensitiveHelpSetter
{
public:
wxFBContextSensitiveHelpSetter()
{
wxHelpProvider::Set( new wxHelpControllerHelpProvider );
}
};

static wxFBContextSensitiveHelpSetter s_wxFBSetTheHelpProvider;
///////////////////////////////////////////////////////////////////////////
using namespace ui;

AboutDialog::AboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Visual-Litesql"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText4->Wrap( -1 );
	bSizer4->Add( m_staticText4, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("Version"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText5->Wrap( -1 );
	bSizer4->Add( m_staticText5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_btnClose = new wxButton( this, wxID_OK, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnClose, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer4 );
	this->Layout();
}

AboutDialog::~AboutDialog()
{
}

MainFrame2::MainFrame2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->SetSashGravity( 1 );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame2::m_splitter1OnIdle ), NULL, this );
	
	m_panel1 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_treeCtrl1 = new wxTreeCtrl( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( 30,-1 ), wxTR_DEFAULT_STYLE );
	m_treeCtrl1->SetMinSize( wxSize( 40,-1 ) );
	m_treeCtrl1->SetMaxSize( wxSize( 200,-1 ) );
	
	bSizer4->Add( m_treeCtrl1, 1, wxALL|wxEXPAND, 5 );
	
	m_panel1->SetSizer( bSizer4 );
	m_panel1->Layout();
	bSizer4->Fit( m_panel1 );
	m_panel2 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook1 = new wxNotebook( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer5->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );
	
	m_splitter3 = new wxSplitterWindow( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame2::m_splitter3OnIdle ), NULL, this );
	
	m_panel4 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl1 = new wxListCtrl( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer8->Add( m_listCtrl1, 1, wxALL|wxEXPAND, 5 );
	
	m_panel4->SetSizer( bSizer8 );
	m_panel4->Layout();
	bSizer8->Fit( m_panel4 );
	m_splitter3->Initialize( m_panel4 );
	bSizer5->Add( m_splitter3, 1, wxEXPAND, 5 );
	
	m_panel2->SetSizer( bSizer5 );
	m_panel2->Layout();
	bSizer5->Fit( m_panel2 );
	m_splitter1->SplitVertically( m_panel1, m_panel2, 0 );
	bSizer9->Add( m_splitter1, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer9 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	this->SetMenuBar( m_menubar1 );
	
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	m_toolBar1->AddTool( wxID_ANY, _("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar1->AddSeparator(); 
	m_toolBar1->AddTool( wxID_ANY, _("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar1->AddTool( wxID_ANY, _("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar1->AddTool( wxID_ANY, _("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar1->Realize();
	
	
	this->Centre( wxBOTH );
}

MainFrame2::~MainFrame2()
{
}

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	this->SetSizer( bSizer6 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 3, wxST_SIZEGRIP, wxID_ANY );
	m_mainMenu = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	wxMenuItem* m_menuItemExit;
	m_menuItemExit = new wxMenuItem( m_menuFile, wxID_ANY, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuItemExit );
	
	m_mainMenu->Append( m_menuFile, _("File") ); 
	
	this->SetMenuBar( m_mainMenu );
	
	
	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}
