//
// Created by atuser on 9/26/19.
//

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
	
	printf("%f inches == %f centimeters\n", input_inches, cm);
	if(cm > 50)
		printf("cm is greater than 50\n");
	else
		printf("cm is less than 50\n");
	
	while(cm > 50) {
		cm /= 2;
		printf("cm %f\n", cm);
	}
	
	for(int i = 0;i < 4; i++)
	{
		cm *= 2;
		printf("%d: cm is %f\n", i, cm);
	}
	
	return 0;
}
