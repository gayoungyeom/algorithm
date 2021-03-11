#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int cur, vector<int> numbers, int target, int cal_val){
    unsigned int next = cur + 1;
	if(next == numbers.size()){
		if(cal_val == target) answer++;
		return;
	}
	dfs(next, numbers, target, cal_val + numbers[next]);
	dfs(next, numbers, target, cal_val - numbers[next]);
}

int solution(vector<int> numbers, int target) {
    dfs(0, numbers, target, numbers[0]);
    dfs(0, numbers, target, -numbers[0]);
    return answer;
}
