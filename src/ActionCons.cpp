// -*- C++ -*-
/*!
 * @file  ActionCons.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "ActionCons.h"

// Module specification
// <rtc-template block="module_spec">
static const char* actioncons_spec[] =
  {
    "implementation_id", "ActionCons",
    "type_name",         "ActionCons",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
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
ActionCons::ActionCons(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_sv_namePort("sv_name")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ActionCons::~ActionCons()
{
}



RTC::ReturnCode_t ActionCons::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_sv_namePort.registerProvider("ssr_RTMActionSampleCallback", "ssr::RTMActionSampleCallback", m_callback);
  
  // Set service consumers to Ports
  m_sv_namePort.registerConsumer("ssr_RTMActionSample", "ssr::RTMActionSample", m_service);
  
  // Set CORBA Service Ports
  addPort(m_sv_namePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ActionCons::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionCons::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionCons::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionCons::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionCons::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ActionCons::onExecute(RTC::UniqueId ec_id)
{
	std::cout << "ActionConst: SetGoal (100)" << std::endl;
	ssr::RTMActionSampleGoal_var goal(new ssr::RTMActionSampleGoal());
	goal->goal = 100;
	m_service->setGoal(goal);

	coil::usleep(10 * 1000 * 1000);
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t ActionCons::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionCons::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionCons::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionCons::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionCons::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ActionConsInit(RTC::Manager* manager)
  {
    coil::Properties profile(actioncons_spec);
    manager->registerFactory(profile,
                             RTC::Create<ActionCons>,
                             RTC::Delete<ActionCons>);
  }
  
};


