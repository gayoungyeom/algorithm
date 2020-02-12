#include <iostream>
using namespace std;

bool hasTrpSix(int num){
	int cnt = 0;
	while(num > 0){
		if(num % 10 == 6){
			cnt++;
		}
		else{
			if(cnt < 3) cnt = 0;
		}
		num /= 10;
	}
	if(cnt < 3) return false;
	else return true;
}

int main(){
	int n, ans;
	cin>>n;

	if(n == 1){
		cout<<666<<'\n';
		return 0;
	}

	int num = 666;
	int cnt = 1;
	while(cnt != n){
		num++;
		if(hasTrpSix(num)){
			ans = num;
			cnt++;
		}
	}
	cout<<ans;

	return 0;
}

