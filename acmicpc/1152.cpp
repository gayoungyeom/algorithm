#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000000

int main(){
	char s[MAX];
	cin.getline(s, MAX);

	int cnt = 1;
	for(unsigned int i=0; i<strlen(s); i++)
		if(s[i] == ' ') cnt++;
	if(s[0] == ' ') cnt--;
	if(s[strlen(s) -1] == ' ') cnt--;

	cout<<cnt;

	return 0;
}
