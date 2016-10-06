/*
 * Pin.h
 *
 *  Created on: 5 окт. 2016 г.
 *      Author: director
 */
#include <stdint.h>
#ifndef SRC_PIN_H_
#define SRC_PIN_H_

class Pin {
public:
protected:
	Pin(uint32_t port, uint16_t n)
	{
		this->port = port;
		this->n = n;
	}
	Pin(uint32_t port, uint16_t n)
	{
		this->port = port;
		this->n = n;
	}
	void setDefaultProperties()
	{

		//TODO

	}
	virtual ~Pin();

private:
	uint32_t port;
	uint16_t n;
};

#endif /* SRC_PIN_H_ */
