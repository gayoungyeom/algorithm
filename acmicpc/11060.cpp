#include <iostream>
using namespace std;

int a[1001];
int f[1001];

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		f[i] = -1;
	}

	f[0] = 0;
	for(int i=1; i<n; i++){
		for(int j=0; j<a[i-1]; j++){
			if(f[i+j] == -1){
				if(f[i-1] == -1) break; //더 이상 이동이 불가능한 경우
				else f[i+j] = f[i-1] + 1;
			}
		}
	}

	cout<<f[n-1]<<'\n';

	return 0;
}

