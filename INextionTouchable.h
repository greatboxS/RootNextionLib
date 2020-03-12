/*! \file */

#ifndef __NEONEXTION_INEXTIONTOUCHABLE
#define __NEONEXTION_INEXTIONTOUCHABLE

#include "Nextion.h"
#include "INextionWidget.h"
#include "INextionCallback.h"
#include "NextionCallbackFunctionHandler.h"

/*!
 * \class INextionTouchable
 * \brief Interface for widgets that can be touched.
 */
class INextionTouchable : public virtual INextionWidget
{
public:
	INextionTouchable(Nextion& nex, uint8_t page, uint8_t component,
		const char* name);

	INextionTouchable(Nextion& nex);

	bool processEvent(uint8_t pageID, uint8_t componentID, uint8_t eventType);

	bool root_processEvent(uint8_t pageID, uint8_t componentID, uint8_t eventType);

	bool attachCallback(NextionCallbackFunctionHandler::NextionFunction cb);

	bool root_attachCallback(NextionCallbackFunctionHandler::RootNextionFunction cb);
	bool attachCallback(INextionCallback* obj);
	void detachCallback();



private:

	bool root = false;
	bool normal = false;
	INextionCallback* m_callback;
};

#endif
