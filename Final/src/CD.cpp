/*
 * CD.cpp
 *
 *  Created on: May 21, 2012
 *      Author: Pallavi
 */

#include "CD.h"
#include "Savings.h"


CD::CD(const string &name, float bal):Savings(name, bal) {


}
float CD::Calculate() {
	float rate;
	int balFraction;
	if (currentBalance < 2500) {
		rate = 0.05;
	} else {
		balFraction = currentBalance / 2500;
		rate = 0.05+( 0.0025 * balFraction);
	}

	currentBalance = currentBalance + (currentBalance * rate);
	return currentBalance;

}

CD::~CD() {

}

