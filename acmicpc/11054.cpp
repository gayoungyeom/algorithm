#include <iostream>
using namespace std;

int A[1001];
int inLen[1001];
int deLen[1001];
int length[1001];

void LIS(int n){
	inLen[1] = 1;
	for(int i=2; i<=n; i++){
		int max = 0;
		for(int j=i-1; j>0; j--){
			if(A[j]<A[i] && inLen[j]>max) max = inLen[j];
		}
		inLen[i] = max + 1;
	}
}

//뒤에서 부터 시작하는 lis
void revLIS(int n){
	deLen[n] = 1;
	for(int i=n-1; i>0; i--){
		int max = 0;
		for(int j=i+1; j<=n; j++){
			if(A[j]<A[i] && deLen[j]>max) max = deLen[j];
		}
		deLen[i] = max + 1;
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>A[i];

	LIS(n);
	revLIS(n);

	int ans = 1;
	for(int i=1; i<=n; i++){
		length[i] = inLen[i] + deLen[i];
		ans = max(ans, length[i]);
	}
	cout<<ans - 1<<'\n';

	return 0;
}

