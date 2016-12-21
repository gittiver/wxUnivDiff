#include <cxxtest/TestSuite.h>
#include "cmdline.hpp"
#include <wx/cmdline.h>

class CmdLineTestSuite : public CxxTest::TestSuite 
{
public:
  wxCmdLineParser* parser; 
  void setUp() 
  {
    parser = new wxCmdLineParser();
  }

  void tearDown()
  {
    delete parser;
  }

   void testIsCmdLineSwitch()
   {
     parser->SetDesc(getCmdlineEntryDesc());
     wxString cmdLine("test -v");
     parser->SetCmdLine(cmdLine);
     parser->Parse();

     TS_ASSERT_EQUALS(parser->FoundSwitch("v"),wxCMD_SWITCH_ON);

#if defined WIN32

     cmdLine = "test /v";
     parser->SetCmdLine(cmdLine);
     parser->Parse();

     TS_ASSERT_EQUALS(parser->FoundSwitch("v"),wxCMD_SWITCH_ON);
#endif

     cmdLine = "test v";
     parser->SetCmdLine(cmdLine);
     parser->Parse();

     TS_ASSERT_EQUALS(parser->FoundSwitch("v"),wxCMD_SWITCH_NOT_FOUND);
     TS_ASSERT_EQUALS(parser->GetParam(1),"v");
     
     //TS_ASSERT_EQUALS(isCmdLineSwitch("-v"),true);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("-i"),true);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("-l"),true);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("-a"),true);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("-del"),true);

     //TS_ASSERT_EQUALS(isCmdLineSwitch("--verbose"),true);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("--interactive"),true);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("--list"),true);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("--add"),true);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("--del"),true);

     //TS_ASSERT_EQUALS(isCmdLineSwitch(""),false);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("/a"),false);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("-z"),false);
     //TS_ASSERT_EQUALS(isCmdLineSwitch("--z"),false);
   }

};