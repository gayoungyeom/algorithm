/*
 * count[i]: i를 1로 만드는데 최소 연산 횟수
 */

#include <iostream>
using namespace std;

int count[1000001];

int minCount(int n){
	count[2] = count[3] = 1;
	for(int i=4; i<=n; i++){
		if(i%3 == 0)
			count[i] = min(count[i/3], count[i-1]) + 1;
		else if(i%2 == 0)
			count[i] = min(count[i/2], count[i-1]) + 1;
		else
			count[i] = count[i-1] + 1;
	}
	return count[n];
}

int main(){
	int n;
	cin>>n;
	cout<<minCount(n);
	return 0;
}

