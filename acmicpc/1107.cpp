#include <iostream>
using namespace std;

bool isBroken[10];

int main(){
	int n, m;
	cin>>n>>m;

	int x;
	for(int i=0; i<m; i++){
		cin>>x;
		isBroken[x] = true;
	}

	// + or - 버튼만으로 이동하는 경우를 정답의 초기값으로 설정
	int ans = n - 100;
	if(ans < 0) ans = -ans;

	for(int i=0; i<=1000000; i++){
		string ch = to_string(i);
		int len = ch.length();

		bool isPossible = true;
		for(int j=0; j<len; j++){
			int idx = ch[j] - '0'; //char to int
			if(isBroken[idx]){
				isPossible = false;
				break;
			}
		}

		if(isPossible){
			int press = stoi(ch) - n; //+ or - 누르는 횟수
			if(press < 0) press = -press;

			int tmp = len + press;
			ans = min(ans, tmp);
		}
	}

	cout<<ans<<'\n';

	return 0;
}

