#include <cxxtest/TestSuite.h>
#include "NotificationHelper.hpp"
#include "cmi_transport.hpp"
#include "Service_lite.hpp"
#include "CMCom.pb.h"
#include "CMEnums.pb.h"
#include "CMInterface.pb.h"
#include "SystemInterfaceMockup.hpp"
#include "AbstractCashArea.hpp"

using namespace communication::pb;

class NullRpcChannel : public communication::pb::RpcChannel
{
   uint32_t nextRequestId;

public:
   NullRpcChannel()
      : nextRequestId(0)
   {}

   uint32_t getNextRequestId() { return nextRequestId++; }

   void CallMethod(const Service::MethodDescriptor* method,
      RpcController* controller,
      const google::protobuf::MessageLite* request,
      google::protobuf::MessageLite* response,
      google::protobuf::Closure* done)
   {
      ComMessage theRequest;

      theRequest.set_methodid(method->name());
      theRequest.set_serviceid(method->service()->name());
      theRequest.set_paketid(getNextRequestId());
      theRequest.set_messagetype(::EVENT);
      theRequest.set_messagestatus(NO_FAILURE);

      theRequest.set_data(request->SerializeAsString());

      std::string msg;
      theRequest.SerializeToString(&msg);

      // we dont await an answer here
   }
};

class SerialisationTestSuite : public CxxTest::TestSuite 
{
public:
   EventInterface* pEventDelegate;
   SystemInterface* pSystem;

   void setUp() 
   {
      pEventDelegate = new communication::pb::EventInterface_Stub(new NullRpcChannel());
      pSystem = new SystemInterfaceMockup();
   }

   void testNotifyCashAreaInfo()
   {
      NotificationHelper n(pEventDelegate);
      TS_ASSERT_THROWS_NOTHING(n.notifyCashAreaInfo(NULL));
      ::CashArea* pCashArea = new AbstractCashArea(::CashArea::REEL_STORAGE,1);
      TS_ASSERT_THROWS_NOTHING(n.notifyCashAreaInfo(pCashArea));
      
   }

   void testNotifyCashHandlingConfiguration()
   {
      NotificationHelper n(pEventDelegate);
      TS_ASSERT_THROWS_NOTHING(n.notifyCashHandlingConfiguration(pSystem));
   }

   void testNotifyConfigurationKeys()
   {
      NotificationHelper n(pEventDelegate);
      TS_ASSERT_THROWS_NOTHING(n.notifyConfigurationKeys(pSystem));
   }

   void testNotifyDeviceStatus() 
   {
      NotificationHelper n(pEventDelegate);
      TS_ASSERT_THROWS_NOTHING(n.notifyDeviceStatus(pSystem));
   }

   void testNotifyHardware()
   {
      NotificationHelper n(pEventDelegate);
      uint32_t t= Rtos::RtosTimer::now();

      TS_ASSERT_THROWS_NOTHING(n.notifyHardware(SystemInterface::SENSOR_FREE   , 1, 23, t   ));
      TS_ASSERT_THROWS_NOTHING(n.notifyHardware(SystemInterface::SENSOR_COVERED, 1, 42, t+10));
      TS_ASSERT_THROWS_NOTHING(n.notifyHardware(SystemInterface::SENSOR_FREE   , 1, 23, t+20));
      TS_ASSERT_THROWS_NOTHING(n.notifyHardware(SystemInterface::SENSOR_COVERED, 1, 42, t+30));

      TS_ASSERT_THROWS_NOTHING(n.notifyHardware(SystemInterface::ACTUATOR_OFF  , 0, 23, t   ));
      TS_ASSERT_THROWS_NOTHING(n.notifyHardware(SystemInterface::ACTUATOR_ON   , 0, 42, t+10));
      TS_ASSERT_THROWS_NOTHING(n.notifyHardware(SystemInterface::ACTUATOR_OFF  , 0, 23, t+20));
      TS_ASSERT_THROWS_NOTHING(n.notifyHardware(SystemInterface::ACTUATOR_ON   , 0, 42, t+30));
   }

   void testNotifyStatus() 
   {
      NotificationHelper n(pEventDelegate);
      TS_ASSERT_THROWS_NOTHING(n.notifyStatus());
   }

   void testNotifyTimeStamp()
   {
      NotificationHelper n(pEventDelegate);
      TS_ASSERT_THROWS_NOTHING(n.notifyTimeStamp());
   }

   void testNotifyVersionInfo()
   {
      NotificationHelper n(pEventDelegate);
      TS_ASSERT_THROWS_NOTHING(n.notifyVersionInfo(pSystem));
   }

   void testNotifyErrorIdStringTable()
   {
      NotificationHelper n(pEventDelegate);
      TS_ASSERT_THROWS_NOTHING(n.notifyErrorIdStringTable());
   }

   void testNotifyObjectIdStringTable()
   {
      NotificationHelper n(pEventDelegate);
      TS_ASSERT_THROWS_NOTHING(n.notifyObjectIdStringTable());
   }

   void testNotifyNoteTransaction()
   {
      NotificationHelper n(pEventDelegate);
      NotificationHelper::NoteTransaction t;
      t.note=NULL;
      t.sourceCashAreaId=0;
      t.targetCashAreaId=0;

      TS_ASSERT_THROWS_NOTHING(n.notifyNoteTransaction(t));

      ::BankNote eur5("EUR",5,1,::BankNote::NoteCategoryCAT_0,::BankNote::FitnessCategory_FIT);
      t.note = &eur5;
      TS_ASSERT_THROWS_NOTHING(n.notifyNoteTransaction(t));

      // check other overloaded method
      TS_ASSERT_THROWS_NOTHING(n.notifyNoteTransaction(NULL,0,0));
      TS_ASSERT_THROWS_NOTHING(n.notifyNoteTransaction(&eur5,0,0));

   }

   void testNotifyNoteTransactions()
   {
      NotificationHelper::NoteTransaction t;
      t.note=NULL;
      t.sourceCashAreaId=0;
      t.targetCashAreaId=0;
      
      ::BankNote eur5("EUR",5,1,::BankNote::NoteCategoryCAT_0,::BankNote::FitnessCategory_FIT);
      NotificationHelper::NoteTransaction t2;
      t2.note=&eur5;
      t2.sourceCashAreaId=0;
      t2.targetCashAreaId=0;

      NotificationHelper n(pEventDelegate);
      NotificationHelper::NoteTransactionSequence ts;
      
      // test with empty sequence
      TS_ASSERT_THROWS_NOTHING(n.notifyNoteTransactions(ts));

      // test with a note == NULL
      ts.push_back(&t);
      TS_ASSERT_THROWS_NOTHING(n.notifyNoteTransactions(ts));

      // test with normal entry
      ts.push_back(&t2);
      TS_ASSERT_THROWS_NOTHING(n.notifyNoteTransactions(ts));
   }

};