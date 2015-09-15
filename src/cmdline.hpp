#ifndef CMDLINE_HPP
#define CMDLINE_HPP

#include <wx/cmdline.h>

const wxCmdLineEntryDesc* getCmdlineEntryDesc();

typedef struct {
  bool verbose;
  bool list;
  bool add;
  bool del;
  bool interactive;
  bool diff;
} options_t;

options_t& getOptions();

bool isCmdLineSwitch(const wxString& param);

#endif // #ifndef CMDLINE_HPP
