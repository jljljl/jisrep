/*
 * PinOutputBoolean.h
 *
 *  Created on: 06.10.2016
 *      Author: name
 */

#ifndef PINOUTPUTBOOLEAN_H_
#define PINOUTPUTBOOLEAN_H_

class PinOutputBoolean: public Pin {
public:
	PinOutputBoolean(uint32_t port, uint16_t n) : Pin(port, n)
	{
		setDefaultProperties();
	}

	void setDefaultProperties()
	{
		gpio_mode_setup(port, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, n);
	}
	virtual ~PinOutputBoolean();
};

#endif /* PINOUTPUTBOOLEAN_H_ */
