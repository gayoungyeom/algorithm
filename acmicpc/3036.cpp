#include <iostream>
using namespace std;

int GCD(int a, int b){
	if(b == 0) return a;
	return GCD(b, a % b);
}

int main(){
	int n;
	cin>>n;

	int rings[n];
	for(int i=0; i<n; i++)
		cin>>rings[i];

	for(int i=1; i<n; i++){
		int gcd = GCD(rings[0], rings[i]);
		int child = rings[0] / gcd;
		int parent = rings[i] / gcd;
		cout<<child<<"/"<<parent<<'\n';
	}

	return 0;
}

