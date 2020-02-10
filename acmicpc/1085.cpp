#include <iostream>
using namespace std;

int main(){
	int x, y, w, h;
	cin>>x>>y>>w>>h;

	int up = y;
	int down = y;
	int left = x;
	int right = x;
	int radius = 0;

	while(up != h && down != 0 && left != 0 && right != w){
		up++;
		down--;
		left--;
		right++;
		radius++;
	}

	cout<<radius;

	return 0;
}
