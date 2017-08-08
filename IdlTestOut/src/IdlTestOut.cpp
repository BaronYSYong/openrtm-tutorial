// -*- C++ -*-
/*!
 * @file  IdlTestOut.cpp
 * @brief Idl Out Data Port Test
 * @date $Date$
 *
 * $Id$
 */

#include "IdlTestOut.h"

// Module specification
// <rtc-template block="module_spec">
static const char* idltestout_spec[] =
  {
    "implementation_id", "IdlTestOut",
    "type_name",         "IdlTestOut",
    "description",       "Idl Out Data Port Test",
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
IdlTestOut::IdlTestOut(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outOut("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
IdlTestOut::~IdlTestOut()
{
}



RTC::ReturnCode_t IdlTestOut::onInitialize()
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
RTC::ReturnCode_t IdlTestOut::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestOut::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestOut::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestOut::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestOut::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t IdlTestOut::onExecute(RTC::UniqueId ec_id)
{
  std::cout << "Input value1 (long):" << std::endl;
  std::cin >> m_out.value1;
  std::cout << "Input value2 (float):" << std::endl;
  std::cin >> m_out.value2;  
  m_outOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IdlTestOut::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestOut::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestOut::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestOut::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IdlTestOut::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void IdlTestOutInit(RTC::Manager* manager)
  {
    coil::Properties profile(idltestout_spec);
    manager->registerFactory(profile,
                             RTC::Create<IdlTestOut>,
                             RTC::Delete<IdlTestOut>);
  }
  
};


