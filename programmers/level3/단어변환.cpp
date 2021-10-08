#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {    
    bool flag = false;
    for(unsigned int i=0; i<words.size(); i++)
        if(words[i] == target) flag = true;
    
    if(flag){    
        queue<pair<string, int>> q;
        q.push({begin, 0});

        while(!q.empty()){
            string str = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            if(str == target) return depth;

            for(unsigned int i=0; i<words.size(); i++){
                int cnt = 0;
                for(int j=0; j<begin.length(); j++){
                    if(str[j] != words[i][j]){
                        cnt++;
                        if(cnt > 2) break;
                    }
                }

                if(cnt == 1)
                    q.push({words[i], depth + 1});
            }   
        }
    }
    else return 0;
}
