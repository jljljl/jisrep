/*
 * PinSpace.h
 *
 *  Created on: 5 ���. 2016 �.
 *      Author: director
 */

#ifndef SRC_PINSPACE_H_
#define SRC_PINSPACE_H_

class PinSpace
{
public:

	PinSpace(int pins)
	{
		val = false;
		this->pins = pins;
	}
	virtual ~PinSpace();

private:
	int pins;
	bool val;

};


#endif /* SRC_PINSPACE_H_ */
