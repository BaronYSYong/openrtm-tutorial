// -*- C++ -*-
/*!
 * @file  IdlTestIn.cpp
 * @brief Idl Test input port
 * @date $Date$
 *
 * $Id$
 */

#include "IdlTestIn.h"

// Module specification
// <rtc-template block="module_spec">
static const char* idltestin_spec[] =
  {
    "implementation_id", "IdlTestIn",
    "type_name",         "IdlTestIn",
    "description",       "Idl Test input port",
    "version",           "1.0.0",
    "vendor",            "Baron Yong",
    "category",          "Example",
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
IdlTestIn::IdlTestIn(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
IdlTestIn::~IdlTestIn()
{
}



RTC::ReturnCode_t IdlTestIn::onInitialize()
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
RTC::ReturnCode_t IdlTestIn::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestIn::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestIn::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestIn::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestIn::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t IdlTestIn::onExecute(RTC::UniqueId ec_id)
{
  if (m_inIn.isNew())
  {
    m_inIn.read();
    std::cout << "Value 1 (long) = " << m_in.value1 << std::endl;
    std::cout << "Value 2 (float) =  " << m_in.value2 << std::endl;
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IdlTestIn::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestIn::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestIn::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestIn::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestIn::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void IdlTestInInit(RTC::Manager* manager)
  {
    coil::Properties profile(idltestin_spec);
    manager->registerFactory(profile,
                             RTC::Create<IdlTestIn>,
                             RTC::Delete<IdlTestIn>);
  }
  
};


