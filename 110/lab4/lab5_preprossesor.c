//
// Created by atuser on 9/26/19.
//

#include <stdio.h>

#define IN2CM(in) (in) * 2.54;
#define MSG "Inches to convert: "

int main (int argc, char** argv) {
	printf(MSG);
	
	float input_inches;
	scanf("%f", &input_inches);
	
	float cm = IN2CM(input_inches);
	
	printf("%f inches == %f centimeters", input_inches, cm);
	
	return 0;
}
