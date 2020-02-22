#include <iostream>
using namespace std;

long long f[100];

long long fib(long long n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(f[n] != 0) return f[n];
	f[n] = fib(n-1) + fib(n-2);
	return f[n];
}

int main(){
	int n;
	cin>>n;
	cout<<fib(n);
	return 0;
}

