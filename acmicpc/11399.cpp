#include <iostream>
#include <algorithm>
using namespace std;

int P[1001];

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>P[i];

	sort(P, P + n);

	int sum = P[0];
	for(int i=1; i<n; i++){
		P[i] += P[i-1];
		sum += P[i];
	}

	cout<<sum<<'\n';

	return 0;
}
