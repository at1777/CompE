// ===========================================================
//
// Lab6_Register.cpp
// Description: AMBA Register
// Name: <team member names here>
// Date: <today's date here>
// Class: CMPE-110
// Section: <Lab: section, day, and time here>
//
// ===========================================================

#include "stdio.h"

int main() {
    unsigned char amba=0;

    //initial value of the amba register
    printf("After initialization, amba = 0x%X\n",amba);

    //set 'Mode bit' and 'Enable bit' high
    amba = amba | ((1 << 7) | (1 << 6)); //you need to change this line!
    printf("After mode and enable bits set, amba = 0x%X\n",amba);

    //also set the 'prescale' bits so 'clock divide by' is 16
    amba = amba | (1 << 2); //you need to change this line!
    printf("After setting prescale bits, amba = 0x%X\n",amba);

    //clear the 'Mode bit', leaving other bits alone
    amba = amba &(~(1 << 6)); //you need to change this line!
    printf("After clearing the mode bit, amba = 0x%X\n",amba);

    return 0;
}
