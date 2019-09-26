//
// Created by atuser on 9/26/19.
//

#include <stdio.h>

float in2cm(float inches) {
	float cm = inches * (float)2.54;
	return cm;
}

int main (int argc, char** argv) {
	printf("Inches to convert: ");
	
	float input_inches;
	scanf("%f", &input_inches);
	
	float cm = in2cm(input_inches);
	
	printf("%f inches == %f centimeters", input_inches, cm);
	
	return 0;
}
