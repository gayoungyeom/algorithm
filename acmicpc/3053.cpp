#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int main(){
	int r;
	cin>>r;

	printf("%.6f\n", r * r * M_PI);
	printf("%.6f\n", pow(sqrt(2) * r, 2)); //2 * r * r

	return 0;
}
