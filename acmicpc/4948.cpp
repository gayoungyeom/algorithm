#include <iostream>
using namespace std;

bool isPrimeNum[250000];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	while(cin>>n){
		if(n < 0) continue;
		if(n == 0) break;

		for(int i=2; i<=2*n; i++){
			isPrimeNum[i] = true;
		}

		for(int i=2; i<=2*n; i++){
			if(isPrimeNum[i]){
				for(int j=2; i*j<=2*n; j++){
					isPrimeNum[i*j] = false;
				}
			}
		}

		int cnt = 0;
		for(int i=n+1; i<=2*n; i++){
			if(isPrimeNum[i]){
				cnt++;
			}
		}
		cout<<cnt<<'\n';
	}

	return 0;
}

