#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char s[15];
	cin>>s;

	int num[strlen(s)];
	int sum = 0;
	for(unsigned int i=0; i<strlen(s); i++){
		int idx = s[i] - 'A';
		if(idx < 15) num[i] = idx / 3 + 2;
		else if(15 <= idx && idx < 19) num[i] = 7;
		else if(19 <= idx && idx < 22) num[i] = 8;
		else  num[i] = 9;
		sum += (num[i] + 1) ;
	}
	cout<<sum;

	return 0;
}
