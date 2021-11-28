#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int cnt = 0;
		int num = 0;
		while(1){
			cnt++;
			num = ((num % n) * 10 + 1) % n;
			if(num == 0){
				cout<<cnt<<'\n';
				break;
			}
		}
	}
	return 0;
}
