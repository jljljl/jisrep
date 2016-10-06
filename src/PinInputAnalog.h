/*
 * PinInputAnalog.h
 *
 *  Created on: 06.10.2016
 *      Author: name
 */

#ifndef PININPUTANALOG_H_
#define PININPUTANALOG_H_

class PinInputAnalog: public Pin {
public:
	PinInputAnalog(uint32_t port, uint16_t n): Pin(port, n)
	{
		setDefaultProperties();
	}

	void setDefaultProperties()
	{
		rcc_periph_clock_enable(RCC_ADC1);
	}
	uint16_t getValue();
	double getRelativeValue();
	virtual ~PinInputAnalog();
};

#endif /* PININPUTANALOG_H_ */
