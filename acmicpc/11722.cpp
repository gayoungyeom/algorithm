#include <iostream>
using namespace std;

int A[1001];
int length[1001];

int dp(int n){
	int answer = 1;
	length[1] = 1;
	for(int i=2; i<=n; i++){
		int max = 0;
		for(int j=i-1; j>0; j--){
			if(A[j]>A[i] && length[j]>max) max = length[j];
		}
		length[i] = max + 1;
		if(length[i] > answer) answer = length[i];
	}
	return answer;
}

int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>A[i];

	cout<<dp(n);
    
	return 0;
}

