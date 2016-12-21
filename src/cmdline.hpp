#ifndef CMDLINE_HPP
#define CMDLINE_HPP

struct wxCmdLineEntryDesc;
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

#endif // #ifndef CMDLINE_HPP
