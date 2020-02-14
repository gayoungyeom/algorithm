// 초기 배열을 저장하면 8MB의 메모리를 초과한다.
#include <iostream>
using namespace std;

int C[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, a;
	cin>>n;

	int k = 0; //주어진 범위 내에서 가장 큰 값
	//각 숫자의 개수 카운팅
	for(int i=0; i<n; i++){
		cin>>a;
		C[a]++;
		k = max(k, a);
	}

	//각 숫자의 개수 출력
	for(int i=1; i<=k; i++){
		for(int j=0; j<C[i]; j++){
			cout<<i<<'\n';
		}
	}

	return 0;
}

