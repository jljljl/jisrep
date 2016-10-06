/*
 * PinInputBoolean.h
 *
 *  Created on: 5 окт. 2016 г.
 *      Author: director
 */

#ifndef SRC_PININPUTBOOLEAN_H_
#define SRC_PININPUTBOOLEAN_H_

#include "Pin.h"
#include <libopencm3/stm32/gpio.h>

class PinInputBoolean: public Pin {
protected:
	PinInputBoolean(uint32_t port, uint16_t n) : Pin(port, n)
	{

	}

	void setDefaultProperties()
	{

		gpio_mode_setup(port, GPIO_MODE_INPUT, GPIO_PUPD_NONE, n);

	}

	virtual ~PinInputBoolean();
};

#endif /* SRC_PININPUTBOOLEAN_H_ */
