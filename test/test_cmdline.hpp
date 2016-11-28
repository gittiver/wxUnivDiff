#include <cxxtest/TestSuite.h>
#include "cmdline.hpp"

class CmdLineTestSuite : public CxxTest::TestSuite 
{
public:

   void setUp() 
   {}

   void testIsCmdLineSwitch()
   {
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