#include <iostream>
using namespace std;

int main(){
	int h, w, n, T;
	cin>>T;

	for(int i=0; i<T; i++){
		cin>>h>>w>>n;
		int floor = n % h;
		int ho = n / h + 1;
		if(floor == 0){
			floor = h;
			ho = n / h;
		}
		if(ho < 10)	cout<<floor<<0<<ho<<endl;
		else cout<<floor<<ho<<endl;
	}

	return 0;
}

