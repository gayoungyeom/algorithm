#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char alpha[256]; //alpha[c]: 문자 c에 대응하는 숫자

//현재 순열에 대한 단어 합 계산
int calc(vector<string> &words, vector<char> &letters, vector<int> &d){
	int size = letters.size();
	int sum = 0;
	for(int i=0; i<size; i++)
		alpha[letters[i]] = d[i];

	for(string s: words){
		int now = 0;
		for(char c: s)
			now = now * 10 + alpha[c];
		sum += now;
	}

	return sum;
}

int main(){
	int n;
	cin>>n;

	vector<string> words(n);
	vector<char> letters;

	for(int i=0; i<n; i++){
		cin>>words[i];
		for(char c: words[i]){ //알파벳 개수 알아내기 위함
			letters.push_back(c);
		}
	}

	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());

	int cnt = letters.size();
	vector<int> d; //숫자 순열 저장 (9부터 cnt개의 숫자)
	for(int i=9; i>9-cnt; i--)
		d.push_back(i);


	sort(d.begin(), d.end());

	int ans = 0;
	do{ //d의 모든 순열 구해가면서 단어 합 계산
		int now = calc(words, letters, d);
		ans = max(ans, now);
	} while(next_permutation(d.begin(), d.end()));

	cout<<ans<<'\n';

	return 0;
}

