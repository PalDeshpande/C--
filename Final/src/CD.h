/*
 * CD.h
 *
 *  Created on: May 21, 2012
 *      Author: Pallavi
 */

#ifndef CD_H_
#define CD_H_

#include "Savings.h"

class CD: public Savings {
public:
	CD(const string &,float= 0.0);
	virtual ~CD();
	float Calculate();
};

#endif /* CD_H_ */
