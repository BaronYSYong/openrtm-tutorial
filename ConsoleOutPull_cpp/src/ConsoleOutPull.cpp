// -*- C++ -*-
/*!
 * @file  ConsoleOutPull.cpp
 * @brief Console Out Component Pull type
 * @date $Date$
 *
 * $Id$
 */

#include "ConsoleOutPull.h"

// Module specification
// <rtc-template block="module_spec">
static const char* consoleoutpull_spec[] =
  {
    "implementation_id", "ConsoleOutPull",
    "type_name",         "ConsoleOutPull",
    "description",       "Console Out Component Pull type",
    "version",           "1.0.0",
    "vendor",            "Baron Yong",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ConsoleOutPull::ConsoleOutPull(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConsoleOutPull::~ConsoleOutPull()
{
}



RTC::ReturnCode_t ConsoleOutPull::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleOutPull::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutPull::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutPull::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutPull::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutPull::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ConsoleOutPull::onExecute(RTC::UniqueId ec_id)
{
  if ( m_inIn.read() ) {
    std::cout << "Data is " << m_in.data <<
    std::endl;
  } else {
    std::cout << "No Connection." << std::endl;
  }
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t ConsoleOutPull::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutPull::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutPull::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutPull::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutPull::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ConsoleOutPullInit(RTC::Manager* manager)
  {
    coil::Properties profile(consoleoutpull_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConsoleOutPull>,
                             RTC::Delete<ConsoleOutPull>);
  }
  
};


