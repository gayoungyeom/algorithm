#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	if(n < 100){
		cout<<n;
		return 0;
	}

	int cnt = 0;
	for(int i=100; i<=n; i++){
		int a = i / 100; //100의 자리
		int b = (i / 10) % 10; //10의 자리
		int c = i % 10; //1의 자리
		if((b - a) == (c - b)){
			cnt++;
		}
	}
	cout<<cnt + 99;

	return 0;
}
