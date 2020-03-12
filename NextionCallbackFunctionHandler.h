/*! \file */

#ifndef __NEONEXTION_NEXTIONCALLBACKFUNCTIONHANDLER
#define __NEONEXTION_NEXTIONCALLBACKFUNCTIONHANDLER

#include "INextionCallback.h"

/*!
 * \class NextionCallbackFunctionHandler
 * \brief Event handler for function pointers.
 */
class NextionCallbackFunctionHandler : public INextionCallback
{
public:

  /*!
   * \typedef NextionFunction
   * \brief Event handler function for display events.
   */
  typedef void (*NextionFunction)(NextionEventType, INextionTouchable *);

  //root handle event
  typedef void (*RootNextionFunction)(uint8_t, uint8_t, uint8_t);

  /*!
   * \brief Creates a new function pointer callback handler.
   * \param f Pointer to callback function
   */
  NextionCallbackFunctionHandler(NextionFunction f)
      : m_function(f)
  {
  }

  NextionCallbackFunctionHandler(RootNextionFunction f)
	  : root_function(f)
  {
  }

  /*!
   * \copydoc INextionCallback::handleNextionEvent
   *
   * Displatches the event to the function.
   */
  void handleNextionEvent(NextionEventType type, INextionTouchable *widget)
  {
    if (m_function != NULL)
      m_function(type, widget);
  }

  void root_handleNextionEvent(uint8_t _nexPageId, uint8_t _nexComponentId, uint8_t _eventType)
  {
	  if (root_function != NULL)
		  root_function(_nexPageId, _nexComponentId, _eventType);
  }

private:
  NextionFunction m_function; //!< Pointer to the callback function

  RootNextionFunction root_function; //!< Pointer to the callback function
};

#endif
