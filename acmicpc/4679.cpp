#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		double h, u, d, f;
		cin>>h>>u>>d>>f;
		if(h == 0) break;

		int day = 1;
		double climbed = 0;
		double fatigue = u * (f / 100);
		bool flag = true;

		while(1){
			climbed += u;
			if(climbed > h) break;
			climbed -= d; //position at next day
			if(climbed < 0){
				flag = false;
				break;
			}
			day++;
			u = max(u - fatigue, (double)0);
		}
		if(flag) cout<<"success on day "<<day<<endl;
		else cout<<"failure on day "<<day<<endl;
	}
	return 0;
}
