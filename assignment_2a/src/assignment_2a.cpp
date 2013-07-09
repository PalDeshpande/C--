//============================================================================
// Name        : assignmnt_2a.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// function implemented to print pyramid
void Pyramid(int a) {
	int space = a ;
	int counter = 1;
	int i = 0;

	while(i< a+1) {
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
		i++;
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
