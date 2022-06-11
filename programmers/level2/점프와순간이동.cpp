#include <iostream>
using namespace std;

int ans = 1;

int solution(int n){
	while(n > 1){
		if(n % 2 == 0){
			n /= 2;
		}else{
			ans++;
			n -= 1;
		}
	}
	return ans;
}
