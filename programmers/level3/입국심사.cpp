#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	sort(times.begin(), times.end());

	long long left = 0;
	long long right = (long long)times[times.size() -1] * n;

	while(left <= right){
		long long mid = (left + right) / 2;

		long long cnt = 0;
		for(unsigned int i=0; i<times.size(); i++)
			cnt += mid / times[i];

		if(cnt < n){ 
			left = mid + 1;
		} else{ 
			answer = mid;
			right = mid - 1;
		}
	}
	return answer;
}
