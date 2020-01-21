#include <iostream>
using namespace std;

bool isPrimeNum(int num){
	if(num <= 1) return false;
	for(int i=2; i<num; i++){
		if(num % i == 0) return false;
	}
	return true;
}

int main(){
	int n, num;
	int count = 0;
	cin>>n;

	for(int i=0; i<n; i++){
		cin>>num;
		if(isPrimeNum(num)) count++;
	}
	cout<<count;

	return 0;
}
