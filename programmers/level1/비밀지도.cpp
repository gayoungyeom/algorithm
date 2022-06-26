#include <string>
#include <vector>
using namespace std;

int a[20][20];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {    
    for(int i=0; i<n; i++){
        int cur1 = arr1[i];
        int cur2 = arr2[i];
        for(int j=n-1; j>=0; j--){
            int check1 = (cur1&(1<<j));
            int check2 = (cur2&(1<<j));
            if(check1 || check2) a[i][n-j-1] = 1;
            else a[i][n-j-1] = 0;
        }
    }
    
    vector<string> ans;
    for(int i=0; i<n; i++){
        string s = "";
        for(int j=0; j<n; j++){
            if(a[i][j]) s += "#";
            else s += " ";
        }
        ans.push_back(s);
    }
    
    return ans;
}
