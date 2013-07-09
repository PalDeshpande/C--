/*
 * pensionEmployee.h
 *
 *  Created on: Apr 9, 2012
 *      Author: Pallavi
 */

#ifndef PENSIONEMPLOYEE_H_
#define PENSIONEMPLOYEE_H_
#include "CommissionEmployee.h"
class pensionEmployee{
	CommissionEmployee CE;
	 double pension;
public:
	 pensionEmployee(const string &, const string &, const string &,
      double = 0.0, double = 0.0, double =0.0);
	 void setPension(double amt);
	 void getDetails();

};



#endif /* PENSIONEMPLOYEE_H_ */
