#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib> //int abs header
using namespace std;

int n;
int s[21][21];
int visited[21];
vector<int> v;
vector<int> ability; //ability[0]~[mid]: start team, ability[mid+1]~[end]: link team

void backtrack(int cur){
	if((int)v.size() == n/2){
		int sum = 0;
		for(int i=0; i<n/2; i++){
			int row = v[i] - 1;
			for(int j=0; j<n/2; j++){
				sum += s[row][v[j] - 1];
			}
		}
		ability.push_back(sum);
		return;
	}

	//n개 중 절반 선택하는 방법
	visited[cur] = true;
	for(int i=cur; i<=n; i++){
		if(!visited[i]){
			v.push_back(i);
			backtrack(i);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main(){
	cin>>n;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>s[i][j];

	backtrack(0);

	int ans = INT_MAX;
	int s = (int)ability.size();
	for(int i=0; i<s/2; i++){
		ability[i] -= ability[s - i - 1];
		int p = abs(ability[i]);
		if(p < ans)
			ans = p;
	}
	cout<<ans;

	return 0;
}

