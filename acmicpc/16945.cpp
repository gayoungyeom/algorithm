#include <iostream>
#include <vector>
using namespace std;

int a[3][3];

vector<vector<int>> magic_sq[] = {
		{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
		{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
		{{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
		{{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
		{{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
		{{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
		{{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
		{{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
};

int main(){
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			cin>>a[i][j];

	int ans = -1;
	for(int k=0; k<8; k++){
		int cost = 0;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				int diff = a[i][j] - magic_sq[k][i][j];
				if(diff < 0) diff = -diff;
				cost += diff;
			}
		}
		if(ans == -1) ans = cost;
		else ans = min(ans, cost);
	}

	cout<<ans<<'\n';

	return 0;
}

