/*
 * minCost[i][color]: i번째 집에서 color를 칠한 경우 최소 비용
 */

#include <iostream>
using namespace std;

int minCost[1001][1001];

int min(int r, int g, int b){
	int arr[3] = {r, g, b};
	int min = arr[0];
	for(int i=1; i<3; i++){
		if(arr[i] < min) min = arr[i];
	}
	return min;
}

int main(){
	int n;
	cin>>n;

	int cost[n][3];
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin>>cost[i][j];
		}
	}

	//base case
	for(int i=0; i<3; i++){
		minCost[0][i] = cost[0][i];
	}

	for(int i=1; i<n; i++){
		minCost[i][0] = cost[i][0] + min(minCost[i-1][1], minCost[i-1][2]);
		minCost[i][1] = cost[i][1] + min(minCost[i-1][0], minCost[i-1][2]);
		minCost[i][2] = cost[i][2] + min(minCost[i-1][0], minCost[i-1][1]);
	}

	cout<<min(minCost[n-1][0], minCost[n-1][1], minCost[n-1][2]);

	return 0;
}
