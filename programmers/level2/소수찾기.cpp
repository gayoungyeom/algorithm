#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<char> v;
vector<int> nums;

bool isPrimeNum(int num){
    if(num < 2) return false;
    for(int i=2; i<=sqrt(num); i++)
        if(num % i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int len = numbers.length();

    for(int i=0; i<len; i++)
        v.push_back(numbers[i]);

    sort(v.begin(), v.end());

    //가능한 모든 조합 구하기
    for(int i=1; i<=len; i++){
		do{
			string cur = "";
			for(int j=0; j<i; j++)
				cur += v[j];
			nums.push_back(stoi(cur));
		} while(next_permutation(v.begin(), v.end()));
    }

    //중복 제거
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for(unsigned int i=0; i<nums.size(); i++){
    	if(isPrimeNum(nums[i])) answer++;
     }
    
    return answer;
}
