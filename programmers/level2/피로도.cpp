#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int n = dungeons.size();
    vector<int> v; 
    for(int i=0; i<n; i++) v.push_back(i);
    
    int ans = 0;
    do{
        int cnt = 0;
        int p = k;
        for(int i=0; i<n; i++){
            int idx = v[i];
            int need = dungeons[idx][0];
            int use = dungeons[idx][1];
            
            if(need > p) break;
            
            p -= use;
            cnt++;
        }
        ans = max(ans, cnt);
    } while(next_permutation(v.begin(), v.end()));
    
    return ans;
}
