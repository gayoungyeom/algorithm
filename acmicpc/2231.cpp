#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	int ans = 1;
	int flag = false;
	while(ans != n){
		int tmp = ans;
		int sum = 0;
		while(tmp > 0){
			sum += tmp % 10;
			tmp /= 10;
		}
		if(n == (sum + ans)){
			flag = true;
			break;
		}
		ans++;
	}

	if(flag) cout<<ans<<'\n';
	else cout<<0<<'\n';

	return 0;
}

