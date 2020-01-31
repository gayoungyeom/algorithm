#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	int alpha[26];
	int cnt = 0; //그룹 단어가 아닌 단어의 개수
	for(int i=0; i<n; i++){
		string s;
		cin>>s;

		for(int i=0; i<26; i++)
			alpha[i] = 0;

		for(unsigned int j=0; j<s.size(); j++){
			int idx = s[j] - 'a';
			if(!alpha[idx]){ //처음 나온 알파벳의 경우
				alpha[idx] = true;
			}
			else{ //이미 나온 알파벳의 경우
				if(s[j] == s[j-1]){
					continue;
				}
				else{ //그룹 단어가 아닌 경우
					cnt++;
					break;
				}
			}
		}
	}

	cout<<n - cnt;

	return 0;
}
