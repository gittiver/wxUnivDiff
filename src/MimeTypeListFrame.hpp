#ifndef MIMETYPELISTFRAME_HPP
#define MIMETYPELISTFRAME_HPP

#include "ui.h"

class ExtensionConfiguration;

class MimeTypeListFrame: public ui::MimetypeListFrameBase
  {
  public:
    MimeTypeListFrame(ExtensionConfiguration* pModel);

    void loadModel();
    void OnApply( wxCommandEvent& /*event*/ );
    void OnCancel( wxCommandEvent& /*event */);
    void OnOk( wxCommandEvent& /*event*/ );
    void OnHelp( wxCommandEvent& /*event*/ );

    void OnListItemActivated( wxListEvent& event );
  private:
    ExtensionConfiguration* pModel;
  };

#endif // #ifndef MIMETYPELISTFRAME_HPP