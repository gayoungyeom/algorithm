#include <string>
#include <vector>
using namespace std;

int zero, one;

void qt(int x, int y, int n, vector<vector<int>> &arr){
    int cur = arr[x][y];
    if(n == 1){
        if(cur) one++;
        else zero++;
        return;
    }    
    
    bool flag = true;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(cur != arr[i][j]){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    
    if(flag){
        if(cur) one++;
        else zero++;
        return;
    } 
    
    int mid = n/2;
    qt(x, y, mid, arr);
    qt(x, y+mid, mid, arr);
    qt(x+mid, y, mid, arr);
    qt(x+mid, y+mid, mid, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    qt(0, 0, arr.size(), arr);
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}
