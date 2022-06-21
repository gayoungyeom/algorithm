#include <string>
#include <vector>

using namespace std;

int divisor(int n){ 
    int res = 1;
    for(int i=2; i*i<=n; i++){
        int quot = n / i;
        if(quot > 10000000) continue; //블록의 최대범위를 넘어가는 경우 스킵 -> 효율성 테스트의 포인트 부분!
        
        if(n % i == 0){ //약수
            res = quot;
            break;
        }
    }    
    return res;
}

vector<int> solution(long long begin, long long end) {
    vector<int> ans;
    for(int i=begin; i<=end; i++){
        if(i == 1) ans.push_back(0);
        else ans.push_back(divisor(i));
    }
    return ans;
}
