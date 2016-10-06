/*
 * PinInputAnalog.cpp
 *
 *  Created on: 06.10.2016
 *      Author: name
 */

#include "PinInputAnalog.h"

PinInputAnalog::PinInputAnalog() {
	// TODO Auto-generated constructor stub

}

PinInputAnalog::~PinInputAnalog() {
	// TODO Auto-generated destructor stub
}

uint16_t PinInputAnalog::getValue(uint8_t channel)
{
	uint8_t channel_array[16];
	channel_array[0] = channel;
	adc_set_regular_sequence(ADC1, 1, channel_array);
	adc_start_conversion_regular(ADC1);
	while (!adc_eoc(ADC1));
	uint16_t reg16 = adc_read_regular(ADC1);
	return reg16;
}

double PinInputAnalog::getRelativeValue()
{
	return 0;//TODO
}
