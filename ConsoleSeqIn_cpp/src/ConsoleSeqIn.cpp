// -*- C++ -*-
/*!
 * @file  ConsoleSeqIn.cpp
 * @brief Console Sequence In Component
 * @date $Date$
 *
 * $Id$
 */

#include "ConsoleSeqIn.h"

// Module specification
// <rtc-template block="module_spec">
static const char* consoleseqin_spec[] =
  {
    "implementation_id", "ConsoleSeqIn",
    "type_name",         "ConsoleSeqIn",
    "description",       "Console Sequence In Component",
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
ConsoleSeqIn::ConsoleSeqIn(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outOut("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConsoleSeqIn::~ConsoleSeqIn()
{
}



RTC::ReturnCode_t ConsoleSeqIn::onInitialize()
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
RTC::ReturnCode_t ConsoleSeqIn::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqIn::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqIn::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqIn::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqIn::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ConsoleSeqIn::onExecute(RTC::UniqueId ec_id)
{	
	std::string value;
	std::cout << "Input number:" << std::ends;
	std::getline(std::cin, value);
	std::cout << "Data is " << value << std::endl;
	std::stringstream iss(value);
	long num;
	std::vector<long> numbers;
	while(iss >> num) numbers.push_back(num);
	std::cout << "size = " << numbers.size() << std::endl;
	m_out.data.length(numbers.size());
	for(unsigned int i = 0; i < numbers.size(); i++)
		m_out.data[i] = numbers[i];	
	m_outOut.write();
	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleSeqIn::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqIn::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqIn::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqIn::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleSeqIn::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ConsoleSeqInInit(RTC::Manager* manager)
  {
    coil::Properties profile(consoleseqin_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConsoleSeqIn>,
                             RTC::Delete<ConsoleSeqIn>);
  }
  
};


