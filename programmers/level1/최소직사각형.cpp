#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<vector<int>> tmp;
    for(int i=0; i<sizes.size(); i++){
        vector<int> v;
        v.push_back(sizes[i][0]);
        v.push_back(sizes[i][1]);
        
        sort(v.begin(), v.end());
        tmp.push_back(v);
    }
    
    int w = tmp[0][0];
    int h = tmp[0][1];
    for(int i=1; i<tmp.size(); i++){
        w = max(w, tmp[i][0]);
        h = max(h, tmp[i][1]);
    }
    return w * h;
}
