// ===========================================================
//
// Lab6_BitLogic.cpp
// Description: Bit Logic
// Name: Andrei Tumbar, Barak Binyamin
// Date: 10/3/19
// Class: CMPE-110
// Section: 6 5:00PM
//
// ===========================================================

#include "stdio.h"

void print_result(unsigned char c) {
    // Binary
    int c_binary = c;

    for (int i = 0; i < 8; i++) {
        unsigned int truth = c_binary & ((int)1 << 7);
        if (truth)
            printf("1");
        else
            printf("0");
        c_binary <<= 1;
    }

    printf(" 0x%02X", c);
    printf("\n");
    printf("\n");
}

int main() {
	unsigned char A=0x33;
	unsigned char B=0x4F;
	unsigned char result;
	char g = 0x1000;
	printf("%X\n", g);

	//Initial value A, B
	printf("A= 0x%X, B= 0x%X \n", A, B);

	// calculate ~A and then print it

    print_result(A);
    print_result(B);
    print_result(~A);
    print_result(A&B);
    print_result(A|B);
    print_result(A^B);
    print_result(A << 1);
    print_result(B >> 3);
    print_result(A | 0x88);
    print_result(A & (B | 0x88));

	//continue with the rest of the equations in the exercise
	//(i.e. calculate result and print it, for A&B, then A|B, etc.

	return 0;
}