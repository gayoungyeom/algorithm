#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	int real[n];
	for(int i=0; i<n; i++)
		cin>>real[i];

	sort(real, real + n);
	cout<<real[0] * real[n-1];

	return 0;
}

