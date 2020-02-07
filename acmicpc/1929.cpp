//에라토스테네스의 체
#include <iostream>
using namespace std;

bool isPrimeNum[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin>>M>>N;

	for(int i=2; i<=N; i++){
		isPrimeNum[i] = true;
	}
	
	for(int i=2; i<=N; i++){
		if(isPrimeNum[i]){
		for(int j=2; i*j<=N; j++)
				isPrimeNum[i*j] = false;
		}
	}

	for(int i=M; i<=N; i++){
		if(isPrimeNum[i])
			cout<<i<<'\n';
	}
	
	return 0;
}
