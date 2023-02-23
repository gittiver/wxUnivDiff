#include <wx/msgdlg.h>

#include "MimeTypeListFrame.hpp"
#include "extensionconfiguration.hpp"
using namespace ui;

MimeTypeListFrame::MimeTypeListFrame(ExtensionConfiguration* pModel)
  : MimetypeListFrameBase(NULL,wxID_ANY,wxT("Verknuepfte Anwendungen")) 
{
  m_listCtrlMimetypes->InsertColumn(1,_T("Extensions"));
  m_listCtrlMimetypes->InsertColumn(2,_T("Aufruf/ Executable "));
  m_listCtrlMimetypes->InsertColumn(3,_T("Parameter"));
  this->pModel = pModel;

}

void MimeTypeListFrame::loadModel() 
{
  long index=0;
  wxListItem item;
  
  m_listCtrlMimetypes->DeleteAllItems();
  
  if (!pModel) 
  {
    // TODO handle error somehow ...
  }
  else
  {
    m_listCtrlMimetypes->DeleteAllItems();

    for (ExtensionConfiguration::EntryMap::const_iterator 
      it = pModel->getEntries().begin(); 
      it != pModel->getEntries().end();
      ++it
        )
    {
      item.SetText(it->first);
      item.SetColumn(0);
      item.SetId(index);
      index = m_listCtrlMimetypes->InsertItem( item );

      item.SetId(index);
      item.SetColumn(1);
      item.SetText((it->second).executable_string);
      m_listCtrlMimetypes->SetItem(item);

      m_listCtrlMimetypes->SetItem(index, 2, it->second.parameters );
    }
  }
}


void MimeTypeListFrame::OnApply( wxCommandEvent& /*event*/ )
{
  if (pModel) pModel->Write();
}
void MimeTypeListFrame::OnCancel( wxCommandEvent& /*event */)
{
  Close();
}
void MimeTypeListFrame::OnOk( wxCommandEvent& /*event*/ )
{
  if (pModel) pModel->Write();
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
  long index = event.GetIndex();

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
    if (pModel) pModel->setExtension(key,fname.GetFullPath());
  }
}

