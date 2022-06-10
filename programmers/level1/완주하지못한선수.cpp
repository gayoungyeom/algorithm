#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string ans = "";
	unordered_map<string, int> m;
    for(auto c: completion){
    	m[c] += 1;
    }

    for(auto p: participant){
    	m[p] -= 1;
    	if(m[p] < 0){
    		ans = p;
    		break;
    	}
    }
	return ans;
}
