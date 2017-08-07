// -*-C++-*-
/*!
 * @file  SimpleServiceSVC_impl.h
 * @brief Service implementation header of SimpleService.idl
 *
 */

#include "SimpleServiceSkel.h"

#ifndef SIMPLESERVICESVC_IMPL_H
#define SIMPLESERVICESVC_IMPL_H
 
/*!
 * @class SimpleServiceSVC_impl
 * Example class implementing IDL interface service::SimpleService
 */
class service_SimpleServiceSVC_impl
 : public virtual POA_service::SimpleService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~SimpleServiceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   service_SimpleServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~service_SimpleServiceSVC_impl();

   // attributes and operations
   ::CORBA::Long read(::CORBA::Long& data);
   ::CORBA::Long write(::CORBA::Long data);
   ::CORBA::Long reset();

/** Add From Here **/
private:
    long m_data;
public:
    long getData() { return m_data; }
    void setData(long data) {m_data = data;}
};



#endif // SIMPLESERVICESVC_IMPL_H


