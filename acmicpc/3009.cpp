#include <iostream>
using namespace std;

int main(){
	int x, y;
	int nx, ny;
	int arrX[4], arrY[4];
	for(int i=0; i<3; i++){
		cin>>x>>y;
		arrX[i] = x;
		arrY[i] = y;
	}

	if(arrX[0] == arrX[1])	nx = arrX[2];
	else if(arrX[0] == arrX[2])	nx = arrX[1];
	else	nx = arrX[0];

	if(arrY[0] == arrY[1])	ny = arrY[2];
	else if(arrY[0] == arrY[2])	ny = arrY[1];
	else ny = arrY[0];

	cout<<nx<<" "<<ny;

	return 0;
}

