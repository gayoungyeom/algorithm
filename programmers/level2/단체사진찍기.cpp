#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
    string s = "ACFJMNRT";
    int ans = 0;
    do{
        bool ok = true;
        for(int j=0; j<data.size(); j++){
            int idx1 = s.find(data[j][0]);
            int idx2 = s.find(data[j][2]);
            char op = data[j][3];
            int dist = data[j][4] - '0' + 1;
            int diff = idx1 - idx2;
            if(diff < 0) diff = -diff;

            if(op == '='){
                if(dist != diff){
                    ok = false;
                    break;
                }
            } else if(op == '<'){
                if(dist <= diff){
                    ok = false;
                    break;
                }
            } else{
                if(dist >= diff){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) ans++;
    } while(next_permutation(s.begin(), s.end()));
    return ans;
}
