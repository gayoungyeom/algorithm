#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double A, B, V;
	cin>>A>>B>>V;

	int days = ceil((V - A) / (A - B));
	int leftV = V - days * (A - B);
	while(leftV > A){
		leftV -= (A - B);
		days++;
	}
	cout<<days + 1;
	return 0;
}

