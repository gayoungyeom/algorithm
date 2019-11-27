/*
 * f[i]: 2*i 크기의 직사각형을 채우는 방법의 수
 */

#include <iostream>
using namespace std;

int f[1001];

int dp(int n){
    if(n == 1) return 1;
    if(n == 2) return 3;
    if(f[n] != 0) return f[n];
    f[n] = (dp(n-1) + (2 * dp(n-2))) % 10007;
    return f[n];
}

int main(){
	int n;
	cin>>n;
	cout<<dp(n);
    return 0;
}
