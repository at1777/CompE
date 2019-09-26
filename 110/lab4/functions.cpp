//
// Created by atuser on 9/19/19.
//

#include <iostream>


float in2cm(float inches) {
	float cm = inches * (float)2.54;
	
	return cm;
}

void wait_for_response() {
	std::cout << "\n" << "Type any character, then press the" \
		<< "<Enter> key to continue...\n";
	
	char response;
	
	std::cin >> response;
}

int main() {
	float inches;
	float cm;
	std::cout << "Enter float: ";
	std::cin >> inches;
	cm = in2cm(inches);
	std::cout << inches <<" inches == " << cm << " centimeters\n";
	
	
	return 0;
}
