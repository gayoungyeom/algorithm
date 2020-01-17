#include <iostream>
using namespace std;

int main(){
	int n, t;
	int maxSum = 0;
	cin>>n;
	int triangle[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cin>>t;
			triangle[i][j] = t;
		}
	}

	for(int i=1; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j == 0) triangle[i][j] += triangle[i-1][j];
			else if(j == i) triangle[i][j] += triangle[i-1][j-1];
			else triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
		}
	}

	for(int i=0; i<n; i++)
		if(maxSum < triangle[n-1][i]) maxSum = triangle[n-1][i];

	cout<<maxSum;

	return 0;
}

