#include <wx/msgdlg.h>

#include "wxUnivDiffApp.hpp"
#include "MimeTypeListFrame.hpp"

using namespace ui;

MimeTypeListFrame::MimeTypeListFrame()
  : MimetypeListFrameBase(NULL,wxID_ANY,wxT("Verknuepfte Anwendungen")) 
{
  m_listCtrlMimetypes->InsertColumn(1,_T("Extensions"));
  m_listCtrlMimetypes->InsertColumn(2,_T("Aufruf/ Executable "));
  m_listCtrlMimetypes->InsertColumn(3,_T("Parameter"));

}

void MimeTypeListFrame::OnApply( wxCommandEvent& /*event*/ )
{
  WriteExtensions();
}
void MimeTypeListFrame::OnCancel( wxCommandEvent& /*event */)
{
  Close();
}
void MimeTypeListFrame::OnOk( wxCommandEvent& /*event*/ )
{
  WriteExtensions();
  Close();
}
void MimeTypeListFrame::OnHelp( wxCommandEvent& /*event*/ )
{
  // TODO: implement help
  wxMessageBox(_T("Help"));
}

void MimeTypeListFrame::OnListItemActivated( wxListEvent& event )
{
  wxString key;
  wxFileName fname;
  int index = event.GetIndex();

  EditEntryDialog dlg(this);

  dlg.m_textCtrlExtension->SetValue(this->m_listCtrlMimetypes->GetItemText(index,0));
  fname = this->m_listCtrlMimetypes->GetItemText(index,1);
  dlg.m_filePickerCommand->SetFileName(fname);

  int result = dlg.ShowModal();
  if (result==wxID_OK)
  {
    key = dlg.m_textCtrlExtension->GetValue();
    fname = dlg.m_filePickerCommand->GetFileName(); 

    this->m_listCtrlMimetypes->SetItem(index, 0,key );
    this->m_listCtrlMimetypes->SetItem(index, 1,fname.GetFullPath() );
    setExtension(key,fname.GetFullPath());
  }
}
