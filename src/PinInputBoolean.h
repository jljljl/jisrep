/*
 * PinInputBoolean.h
 *
 *  Created on: 5 ���. 2016 �.
 *      Author: director
 */

#ifndef SRC_PININPUTBOOLEAN_H_
#define SRC_PININPUTBOOLEAN_H_

#include "Pin.h"

class PinInputBoolean: public Pin {
protected:
	PinInputBoolean(uint32_t port, uint16_t n) : Pin(port, n)
	{
		setDefaultProperties();
	}

	void setDefaultProperties()
	{
		gpio_mode_setup(port, GPIO_MODE_INPUT, GPIO_PUPD_NONE, n);
	}
	uint16_t getValue();
	virtual ~PinInputBoolean();
};

#endif /* SRC_PININPUTBOOLEAN_H_ */
