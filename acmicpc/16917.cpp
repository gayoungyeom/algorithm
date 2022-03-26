#include <iostream>
using namespace std;

int main(){
	int a, b, c, x, y;
	cin>>a>>b>>c>>x>>y;

	int bb = 0; //반반 개수
	int cost = a*x + b*y + c*bb;
	while(x != 0 && y != 0){
		x--;
		y--;
		bb += 2;
		cost = min(cost, a*x + b*y + c*bb);
	}

	//반반 2개 사는게 더 싼 경우
	while(y > 0){
		y--;
		bb += 2;
		cost = min(cost, b*y + c*bb);
	}
	while(x > 0){
		x--;
		bb += 2;
		cost = min(cost, a*x + c*bb);
	}

	cout<<cost<<'\n';

	return 0;
}

