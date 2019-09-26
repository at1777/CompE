// ===========================================================
//
// Lab4.cpp
// Description: Compute the voltage using ohms law given resistance and current as inputs
// Name: Andrei Tumbar, Brendan Devine
// Date: <09/19/19>
// Class: CMPE-110
// Section: <Lab: 5, Thursday, 5-7>
//
// ===========================================================


#include <iostream>

float calcVoltage(float current, float resistance){
	return current * resistance; // ohms law
}

int main () {
	/* Declare the variables */
	float current;
	float resistance;
	float voltage;
	
	/* Read in input for current and resistance */
	std::cout << "Enter current: ";
	std::cin >> current;
	std::cout << "Enter resistance: ";
	std::cin >> resistance;
	
	/* Compute voltage using ohms law */
	voltage = calcVoltage(current, resistance);
	
	/* Print out the voltage */
	std::cout << voltage <<" Volts" << "\n";
	
	return 0;
}