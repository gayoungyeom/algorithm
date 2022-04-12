#include <iostream>
using namespace std;

int go(int m, int n){
	if(m <= 1) return 0;
	if(n <= 1) return 1;
	if(m == 2) return 2;
	if(n == 2) return 3;
	return go(m-2, n-2) + 4;
}

int main(){
	int m, n;
	cin>>m>>n;
	cout<<go(m, n);
	return 0;
}

