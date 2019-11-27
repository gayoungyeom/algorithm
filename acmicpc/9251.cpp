/*
 * length[i][j]: Xi와 Yj의 lcs
 */

#include <iostream>
using namespace std;

int main(){
	string X;
	string Y;
	cin>>X>>Y;
	X = '0' + X;
	Y = '0' + Y;
	int m = X.length();
	int n = Y.length();
	int length[m][n];

	//base case
	for(int i=0; i<n; i++)
		length[0][i] = 0;
	for(int i=0; i<m; i++)
		length[i][0] = 0;

	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			if(X[i] == Y[j])
				length[i][j] = length[i-1][j-1] +1;
			else
				length[i][j] = max(length[i-1][j], length[i][j-1]);
		}
	}
    
    cout<<length[m-1][n-1];
    
    return 0;
}
