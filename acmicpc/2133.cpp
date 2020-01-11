/*
 * f[i]: 3*i 크기의 직사각형을 채우는 방법의 수
 */

#include <iostream>
using namespace std;

int f[1001];

int dp(int n){
    if(n % 2 != 0) return 0;
    if(n == 0) return 1;
    if(n == 2) return 3;
    if(f[n] != 0) return f[n];
    f[n] = 3 * dp(n-2);
    for(int i=3; i<=n; i++){
    	if(i % 2 == 0)
        	f[n] += 2 * dp(n-i);
    }
    return f[n];
}

int main(){
    int n;
    cin>>n;
    cout<<dp(n);    
    return 0;
}
