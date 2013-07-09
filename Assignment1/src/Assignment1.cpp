//============================================================================
// Name        : Assignment1.cpp
// Author      : Keskar, Pallavi
//Student ID   :008120619
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 1 to add the numbers entered by user in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int size, number, sum = 0;
	cout << "Enter the size" << endl;
	cin >> size;
	if (size <= 0)
		cout << "Invalid size entered" << endl;
	else {

		for (int i = 0; i < size; i++) { //checking if the value of i is exceeding the size entered by the usr.
			cout << "Enter the number to add" << endl;
			cin >> number;
			if(number<0)
				cout<<"Invalid number entered"<<endl;
			else
			sum = sum + number;

		}
	}
	cout << "Sum of the numbers is: " << sum << endl;

	return 0;
}
