#include "cmdline.hpp"

static const wxCmdLineEntryDesc cmdLineDesc[] = {
  { wxCMD_LINE_SWITCH, "v", "verbose", "be verbose" },
  //{ wxCMD_LINE_SWITCH, "q", "quiet",   "be quiet" },

  // { wxCMD_LINE_OPTION, "o", "output",  "output file" },
  { wxCMD_LINE_SWITCH, "i", "interactive",   "interactive mode" },

  { wxCMD_LINE_OPTION, "l", "list",   "list " },
  { wxCMD_LINE_OPTION, "a", "add",   "add entry" },
  { wxCMD_LINE_OPTION, "del", "del",   "del entry" },


  { wxCMD_LINE_PARAM,  NULL, NULL, "input file", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_MULTIPLE| wxCMD_LINE_PARAM_OPTIONAL },

  { wxCMD_LINE_NONE }
};

options_t options = { false,false,false,false,false,false };

const wxCmdLineEntryDesc* getCmdlineEntryDesc() 
{ return cmdLineDesc; }

options_t& getOptions() 
{ return options; }

//bool isCmdLineSwitch(const wxString& param)
//{
//  for (size_t option_index=0;
//    option_index < sizeof(cmdLineDesc)/sizeof(cmdLineDesc[0])-1;
//    ++option_index)
//  {
//    if ( ( cmdLineDesc[option_index].kind == wxCMD_LINE_OPTION ||  cmdLineDesc[option_index].kind == wxCMD_LINE_SWITCH ) )
//    if ( param.StartsWith("-") ) 
//    {
//      if (param.StartsWith("--"))  
//      {
//        if ( param.substr(2).StartsWith(cmdLineDesc[option_index].longName ) ) {
//          return true;
//        }
//      } 
//      else 
//      {
//        if ( param.substr(1).StartsWith(cmdLineDesc[option_index].shortName ) ) {
//          return true;
//        }
//      }
//    }
//  }
//  return false;
//}

