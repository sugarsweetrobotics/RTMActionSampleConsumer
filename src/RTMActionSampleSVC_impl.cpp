// -*-C++-*-
/*!
 * @file  RTMActionSampleSVC_impl.cpp
 * @brief Service implementation code of RTMActionSample.idl
 *
 */

#include "RTMActionSampleSVC_impl.h"

#include <iostream>
/*
 * Example implementational code for IDL interface ssr::RTMActionSample
 */
ssr_RTMActionSampleSVC_impl::ssr_RTMActionSampleSVC_impl()
{
  // Please add extra constructor code here.
}


ssr_RTMActionSampleSVC_impl::~ssr_RTMActionSampleSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
void ssr_RTMActionSampleSVC_impl::setGoal(const ssr::RTMActionSampleGoal& goal)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void ssr_RTMActionSampleSVC_impl::setGoal(const ssr::RTMActionSampleGoal& goal)>"
#endif
}



// End of example implementational code

/*
 * Example implementational code for IDL interface ssr::RTMActionSampleCallback
 */
ssr_RTMActionSampleCallbackSVC_impl::ssr_RTMActionSampleCallbackSVC_impl()
{
  // Please add extra constructor code here.
}


ssr_RTMActionSampleCallbackSVC_impl::~ssr_RTMActionSampleCallbackSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
void ssr_RTMActionSampleCallbackSVC_impl::setFeedback(const ssr::RTMActionSampleFeedback& feedback)
{
	std::cout << "ActionCons: Feedback(" << feedback.current << ")" << std::endl;
}

void ssr_RTMActionSampleCallbackSVC_impl::setResult(const ssr::RTMActionSampleResult& result)
{
	std::cout << "ActionCons: Result(" << result.current << ")" << std::endl;
}



// End of example implementational code



