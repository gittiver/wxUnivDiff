///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
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
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("wxUnivDiff"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
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

MimetypeListFrameBase::MimetypeListFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* verticalBoxSizer;
	verticalBoxSizer = new wxBoxSizer( wxVERTICAL );
	
	m_panel5 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrlMimetypes = new wxListCtrl( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_EDIT_LABELS|wxLC_REPORT );
	bSizer9->Add( m_listCtrlMimetypes, 1, wxEXPAND|wxTOP|wxBOTTOM, 0 );
	
	wxBoxSizer* hButtonBoxSizer;
	hButtonBoxSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( m_panel5, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Apply = new wxButton( m_panel5, wxID_APPLY );
	m_sdbSizer1->AddButton( m_sdbSizer1Apply );
	m_sdbSizer1Cancel = new wxButton( m_panel5, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1Help = new wxButton( m_panel5, wxID_HELP );
	m_sdbSizer1->AddButton( m_sdbSizer1Help );
	m_sdbSizer1->Realize();
	hButtonBoxSizer->Add( m_sdbSizer1, 1, wxTOP|wxBOTTOM, 12 );
	
	
	hButtonBoxSizer->Add( 0, 0, 0, wxEXPAND, 5 );
	
	bSizer9->Add( hButtonBoxSizer, 0, wxEXPAND|wxRIGHT|wxLEFT, 12 );
	
	m_panel5->SetSizer( bSizer9 );
	m_panel5->Layout();
	bSizer9->Fit( m_panel5 );
	verticalBoxSizer->Add( m_panel5, 1, wxEXPAND, 0 );
	
	this->SetSizer( verticalBoxSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_listCtrlMimetypes->Connect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( MimetypeListFrameBase::OnDelete ), NULL, this );
	m_listCtrlMimetypes->Connect( wxEVT_COMMAND_LIST_END_LABEL_EDIT, wxListEventHandler( MimetypeListFrameBase::OnEndEdit ), NULL, this );
	m_listCtrlMimetypes->Connect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( MimetypeListFrameBase::OnInsertItem ), NULL, this );
	m_listCtrlMimetypes->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MimetypeListFrameBase::OnListItemActivated ), NULL, this );
	m_sdbSizer1Apply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MimetypeListFrameBase::OnApply ), NULL, this );
	m_sdbSizer1Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MimetypeListFrameBase::OnCancel ), NULL, this );
	m_sdbSizer1Help->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MimetypeListFrameBase::OnHelp ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MimetypeListFrameBase::OnOk ), NULL, this );
}

MimetypeListFrameBase::~MimetypeListFrameBase()
{
	// Disconnect Events
	m_listCtrlMimetypes->Disconnect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( MimetypeListFrameBase::OnDelete ), NULL, this );
	m_listCtrlMimetypes->Disconnect( wxEVT_COMMAND_LIST_END_LABEL_EDIT, wxListEventHandler( MimetypeListFrameBase::OnEndEdit ), NULL, this );
	m_listCtrlMimetypes->Disconnect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( MimetypeListFrameBase::OnInsertItem ), NULL, this );
	m_listCtrlMimetypes->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MimetypeListFrameBase::OnListItemActivated ), NULL, this );
	m_sdbSizer1Apply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MimetypeListFrameBase::OnApply ), NULL, this );
	m_sdbSizer1Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MimetypeListFrameBase::OnCancel ), NULL, this );
	m_sdbSizer1Help->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MimetypeListFrameBase::OnHelp ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MimetypeListFrameBase::OnOk ), NULL, this );
	
}

EditEntryDialog::EditEntryDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxVERTICAL );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextCommand = new wxStaticText( this, wxID_ANY, _("Command"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCommand->Wrap( -1 );
	fgSizer1->Add( m_staticTextCommand, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_filePickerCommand = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*.*"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST );
	m_filePickerCommand->SetMaxSize( wxSize( 300,-1 ) );
	
	fgSizer1->Add( m_filePickerCommand, 1, wxALL|wxEXPAND, 5 );
	
	m_staticTextExtension = new wxStaticText( this, wxID_ANY, _("Extension"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextExtension->Wrap( -1 );
	fgSizer1->Add( m_staticTextExtension, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlExtension = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_textCtrlExtension, 1, wxALL|wxEXPAND, 5 );
	
	bSizer5->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2OK = new wxButton( this, wxID_OK );
	m_sdbSizer2->AddButton( m_sdbSizer2OK );
	m_sdbSizer2Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer2->AddButton( m_sdbSizer2Cancel );
	m_sdbSizer2Help = new wxButton( this, wxID_HELP );
	m_sdbSizer2->AddButton( m_sdbSizer2Help );
	m_sdbSizer2->Realize();
	bSizer5->Add( m_sdbSizer2, 1, wxEXPAND, 10 );
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

EditEntryDialog::~EditEntryDialog()
{
}
