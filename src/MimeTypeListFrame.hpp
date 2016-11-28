#ifndef MIMETYPELISTFRAME_HPP
#define MIMETYPELISTFRAME_HPP

#include "ui.h"

class MimeTypeListFrame: public ui::MimetypeListFrameBase
  {
  public:
    MimeTypeListFrame();

    void OnApply( wxCommandEvent& /*event*/ );
    void OnCancel( wxCommandEvent& /*event */);
    void OnOk( wxCommandEvent& /*event*/ );
    void OnHelp( wxCommandEvent& /*event*/ );

    void OnListItemActivated( wxListEvent& event );
  };

#endif // #ifndef MIMETYPELISTFRAME_HPP