// -*- C++ -*-
/*!
 * @file  ConsoleSeqOut.cpp
 * @brief Console Sequence Out Component
 * @date $Date$
 *
 * $Id$
 */

#include "ConsoleSeqOut.h"

// Module specification
// <rtc-template block="module_spec">
static const char* consoleseqout_spec[] =
  {
    "implementation_id", "ConsoleSeqOut",
    "type_name",         "ConsoleSeqOut",
    "description",       "Console Sequence Out Component",
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
ConsoleSeqOut::ConsoleSeqOut(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConsoleSeqOut::~ConsoleSeqOut()
{
}



RTC::ReturnCode_t ConsoleSeqOut::onInitialize()
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
RTC::ReturnCode_t ConsoleSeqOut::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqOut::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqOut::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqOut::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqOut::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ConsoleSeqOut::onExecute(RTC::UniqueId ec_id)
{
	if(m_inIn.isNew()) {
		m_inIn.read();
		std::cout << m_in.data.length() << " datas received." << std::endl;
		for(int i = 0;i < m_in.data.length();i++) {
			std::cout << "Data is " << m_in.data[i] << std::endl;
		}
	}
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleSeqOut::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqOut::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqOut::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqOut::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqOut::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ConsoleSeqOutInit(RTC::Manager* manager)
  {
    coil::Properties profile(consoleseqout_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConsoleSeqOut>,
                             RTC::Delete<ConsoleSeqOut>);
  }
  
};


