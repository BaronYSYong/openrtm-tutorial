// -*- C++ -*-
/*!
 * @file  ConsoleIn.cpp
 * @brief Console In Component
 * @date $Date$
 *
 * $Id$
 */

#include "ConsoleIn.h"

// Module specification
// <rtc-template block="module_spec">
static const char* consolein_spec[] =
  {
    "implementation_id", "ConsoleIn",
    "type_name",         "ConsoleIn",
    "description",       "Console In Component",
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
ConsoleIn::ConsoleIn(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outOut("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConsoleIn::~ConsoleIn()
{
}



RTC::ReturnCode_t ConsoleIn::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("out", m_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleIn::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleIn::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleIn::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleIn::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleIn::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ConsoleIn::onExecute(RTC::UniqueId ec_id)
{
  std::cout << "Input number:" << std::endl;
  std::cin >> m_out.data;
  m_outOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleIn::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleIn::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleIn::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleIn::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleIn::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ConsoleInInit(RTC::Manager* manager)
  {
    coil::Properties profile(consolein_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConsoleIn>,
                             RTC::Delete<ConsoleIn>);
  }
  
};


