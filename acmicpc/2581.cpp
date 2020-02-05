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
	int M, N;
	cin>>M>>N;

	int sum = 0;
	int min;
	for(int i=M; i<=N; i++){
		if(isPrimeNum(i)){
			if(sum == 0) min = i;
			sum += i;
		}
	}
	if(sum == 0)
		cout<<-1<<endl;
	else{
		cout<<sum<<endl;
		cout<<min<<endl;
	}
	return 0;
}

