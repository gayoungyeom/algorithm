#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    
    for(unsigned int i=0; i<commands.size(); i++){
        int from = commands[i][0];
        int to = commands[i][1];
        int k = commands[i][2];

        tmp.assign(array.begin() + from - 1, array.begin() + to);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k -1]);
    }
    
    return answer;
}
