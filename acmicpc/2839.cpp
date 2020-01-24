#include <iostream>
using namespace std;

int main(){
	int n;
	int ans = 0;
	bool flag = false;
	cin>>n;

	for(int i=0; i<=1666; i++){ //3
		for(int j=0; j<=1000; j++){ //5
			if(n == (5*i + 3*j)){
				ans = i + j;
				flag = true;
				break;
			}
		}
	}

	if(flag)
		cout<<ans;
	else
		cout<<-1;

	return 0;
}
