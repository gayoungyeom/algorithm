#include <iostream>
using namespace std;

int main(){
	int n, b, h, w;
	int p, a;
	int cost = 2000000;
	bool flag = false;

	cin>>n>>b>>h>>w;
	for(int i=0; i<h; i++){
		cin>>p;
		for(int j=0; j<w; j++){
			cin>>a;
			if(a >= n && (p * n) <= b){
				flag = true;
				if(cost > p * n)
					cost = p * n;
			}
		}
	}
	if(flag) cout<<cost<<endl;
	else cout<<"stay home"<<endl;

	return 0;
}
