#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, ans;
int a[51][51];
int dist[51][51]; //치킨 거리
bool check[51][51]; //m개의 치킨집 선택 여부
vector<pair<int, int>> v; //모든 치킨집 정보
vector<pair<int, int>> ch; //m개의 치킨집 정보

void go(int idx, int cnt){
	if(cnt == m){
		memset(dist, 0, sizeof(dist));
		for(int i=0; i<(int)ch.size(); i++){
			int x = ch[i].first;
			int y = ch[i].second;
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					if(a[j][k] == 1){
						int dx = x - j;
						int dy = y - k;
						if(dx < 0) dx = -dx;
						if(dy < 0) dy = -dy;

						if(dist[j][k] == 0) dist[j][k] = dx + dy;
						else dist[j][k] = min(dist[j][k], dx + dy);
					}
				}
			}
		}

		int sum = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				sum += dist[i][j];
		}
		if(ans == 0) ans = sum;
		else ans = min(ans, sum);

		return;
	}

	for(int i=idx; i<(int)v.size(); i++){
		int x = v[i].first;
		int y = v[i].second;
		if(!check[x][y]){
			check[x][y] = true;
			ch.push_back(make_pair(x, y));
			go(i+1, cnt+1);
			ch.pop_back();
			check[x][y] = false;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
			if(a[i][j] == 2){
				v.push_back(make_pair(i, j));
			}
		}
	}

	go(0, 0);
	cout<<ans<<'\n';

	return 0;
}

