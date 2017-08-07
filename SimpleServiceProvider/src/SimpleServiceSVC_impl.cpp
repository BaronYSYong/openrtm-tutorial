// -*-C++-*-
/*!
 * @file  SimpleServiceSVC_impl.cpp
 * @brief Service implementation code of SimpleService.idl
 *
 */

#include "SimpleServiceSVC_impl.h"

/*
 * Example implementational code for IDL interface service::SimpleService
 */
service_SimpleServiceSVC_impl::service_SimpleServiceSVC_impl()
{
  // Please add extra constructor code here.
}


service_SimpleServiceSVC_impl::~service_SimpleServiceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
::CORBA::Long service_SimpleServiceSVC_impl::read(::CORBA::Long& data)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <CORBA::Long SimpleServiceSVC_impl::read(CORBA::Long& data)>"
#endif
    data = getData();
  return 0;
}

::CORBA::Long service_SimpleServiceSVC_impl::write(::CORBA::Long data)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <CORBA::Long SimpleServiceSVC_impl::write(CORBA::Long data)>"
#endif
    m_data = data;
  return 0;
}

::CORBA::Long service_SimpleServiceSVC_impl::reset()
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <CORBA::Long SimpleServiceSVC_impl::reset()>"
#endif
    long old_data = m_data;
    m_data = 0;
  return old_data;
}



// End of example implementational code



