/*
 * r: 두 원의 반지름 합
 * d: 두 원의 중심사이 거리
 * sqrt를 사용하면 double 값으로 반환되는 것 주의하기!
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	int T;
	int x1, y1, r1, x2, y2, r2;

	cin>>T;
	for(int i=0; i<T; i++){
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		int rplus = r1 + r2;
		int rmin = abs(r1 - r2);
		double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if(d == 0){
			if(r1 == r2) cout<<-1<<endl;
			else cout<<0<<endl;
		}
		else{
			if(d == rplus || d == rmin) cout<<1<<endl;
			else if(rmin < d && d < rplus) cout<<2<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}

