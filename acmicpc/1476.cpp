#include <iostream>
using namespace std;

int main(){
	int e, s, m;
	cin>>e>>s>>m;

	int date[3] = {1, 1, 1};
	int ans = 1;
	while(1){
		if(date[0] == e && date[1] == s && date[2] == m){
			cout<<ans<<'\n';
			break;
		}

		if(date[0] % 15 == 0) date[0] = 1;
		else date[0]++;

		if(date[1] % 28 == 0) date[1] = 1;
		else date[1]++;

		if(date[2] % 19 == 0) date[2] = 1;
		else date[2]++;

		ans++;
	}

	return 0;
}
