#include <iostream>
#include <vector>
using namespace std;

bool isPrimeNum[10001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, T;
	cin>>T;

	for(int i=0; i<T; i++){
		cin>>n;

		for(int i=2; i<=n; i++){
			isPrimeNum[i] = true;
		}

		for(int i=2; i<=n; i++){
			if(isPrimeNum[i]){
				for(int j=2; i*j<=n; j++){
					isPrimeNum[i*j] = false;
				}
			}
		}

		//n보다 작은 소수 찾기
		vector<int> v;
		for(int i=2; i<=n; i++){
			if(isPrimeNum[i]){
				v.push_back(i);
			}
		}

		//파티션 찾기
		int a, b;
		for(unsigned int i=0; i<v.size(); i++){
			for(unsigned int j=i; j<v.size(); j++){
				if(v[i] + v[j] == n){
					//어짜피 마지막에 존재하는 파티션이 두 소수의 차이가 가장 작음
					a = v[i];
					b = v[j];
					break;
				}
			}
		}
		cout<<a<<" "<<b<<'\n';
	}
	return 0;
}

