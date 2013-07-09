//============================================================================
// Name        : assignmnt2.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Function implemented to print pyramid in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// function implemented to print pyramid
void Pyramid(int a) {
	int space = a ;
	int counter = 1;

	for (int i = 1; i < a + 1; i++) {
		//At first layer of the pyramid no of spaces is total no of (layers -1)

		cout << setw(space);
		//first layer of pyramid will always hav only one *

		if (i == 1)
			cout << "*";

		else {
			//logic to decide how many * need to be printed as per the number of that layer

			for (int j = 1; j <= i + counter; j++) {
				cout << "*";
			}
			counter++;

		}
		cout << "\n";
		//no of spaces at each layer will decrease by one
		space--;
	}

}
 //main function
int main() {
	int layers;

	cout << "how many layer should be there in your pyramid?" << endl;
	cin >> layers;
	if (layers == 0) {
		cout << "Pyramid can not have zero layers" << endl;
	} else if (layers == 1) {
		cout << "Single layer can not form a pyramid" << endl;
	} else
		Pyramid(layers);

	return 0;
}
