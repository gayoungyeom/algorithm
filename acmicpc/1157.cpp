#include <iostream>
using namespace std;

int alphaCnt[26];

int main(){
	string s;
	cin>>s;
	for(unsigned int i=0; i<s.size(); i++){
		s[i] = toupper(s[i]); //모두 대문자로 변환
		alphaCnt[s[i] - 'A']++;
	}

	int max = 0;
	int same = 0;
	char ans;
	for(int i=0; i<26; i++){
		if(max <= alphaCnt[i]){
			if(max == alphaCnt[i]){
				same = max;
			}
			else{
				max = alphaCnt[i];
				ans = i + 'A';
			}
		}
	}
	
	if(same == max)
		cout<<"?";
	else
		cout<<ans;

	return 0;
}
