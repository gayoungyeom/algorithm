#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	int last = 1;
	int i = 1;
	while(last < n)
		last = last + 6*i++;

	int ans = i;
	cout<<ans;

	return 0;
}

