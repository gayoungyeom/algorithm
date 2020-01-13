/* 시간복잡도를 O(n)으로 만들기 위해 이차원배열 사용
 *
 * f의 0행은 결과값을 저장하고
 * f의 1행은 n이 3이상일 때부터 발생하는 두가지의 고유한 방법들의 누적치를 저장한다.
 */

#include <iostream>
using namespace std;

long long int f[2][1000001];

long long int dp(int n){
	f[0][0] = 0;
	f[0][1] = 2;
	f[0][2] = 7;
	f[1][2] = 1;
    for(int i=3; i<=n; i++){
    	f[1][i] = (f[0][i-3] + f[1][i-1]) % 1000000007;
    	f[0][i] = (2 * f[0][i-1] + 3 * f[0][i-2] + 2 * f[1][i]) % 1000000007;
    }
    return f[0][n];
}

int main(){
    int n;
    cin>>n;
    cout<<dp(n);
    return 0;
}
