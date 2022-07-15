//long long 타입으로 해야 1번 테케 통과 가능
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isP(long long n){
    if(n < 2) return false;
    for(long long i=2; i*i<=n; i++)
        if(n % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int ans = 0;
    
    //k진수로 변환
    vector<int> v;
    while(n > 0){
        int m = n % k;
        v.push_back(m);
        n /= k;
    }
    
    //P찾기
    long long cur = 0;
    for(int i=v.size()-1; i>=0; i--){
        if(v[i] != 0){
            cur *= 10;
            cur += v[i];
        } else{
            if(isP(cur)) ans++;
            cur = 0;
        }                
    }
    if(cur != 0 && isP(cur)) ans++;
    
    return ans;
}
