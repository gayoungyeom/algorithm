#include <iostream>
using namespace std;

int main(){
	int h, w, x, y;
	cin>>h>>w>>x>>y;

	int B[h+x][w+y];
	for(int i=0; i<h+x; i++){
		for(int j=0; j<w+y; j++)
			cin>>B[i][j];

	for(int i=x; i<x+h; i++)
		for(int j=y; j<y+w; j++)
			B[i][j] -= B[i-x][j-y];

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++)
			cout<<B[i][j]<<" ";
		cout<<'\n';
	}

	return 0;
}

