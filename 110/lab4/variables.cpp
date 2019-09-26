//
// Created by atuser on 9/19/19.
//

#include <iostream>

using namespace std;

void wait_for_response() {
	cout << "\n" << "Type any character, then press the" \
		<< "<Enter> key to continue...\n";
	
	char response;
	
	cin >> response;
}

int main() {
	int ia, ib, ic;
	float fa, fb, fc;
	char ca, cb, cc;
	
	ia = 5;
	ib = 2;
	ic = ia / ib;
	
	cout << ia << " divided by "<< ib << " = "<< ic ;
	cout << " using integer math\n";
	
	fa = 5;
	fb = 2;
	fc = fa / fb;
	
	cout << fa << " divided by "<< fb << " = "<< fc ;
	cout << " using floating point math" << endl;
	
	ca = 5;
	cb = 2;
	cc = ca / cb;
	cout << ca << " divided by "<< cb << " = "<< cc ;
	cout << " using character math\n";
	
	wait_for_response();
	
	unsigned int s = -1;
	printf("%d", (unsigned)s);
	
}