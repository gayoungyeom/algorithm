#include <iostream>
using namespace std;

int n, ans;
int a[11];
bool visited[11];

void go(int w, int cnt){
	if(cnt == n-2){
		ans = max(ans, w);
		return;
	}

	for(int i=1; i<n; i++){
		if(!visited[i]){
			visited[i] = true;

			int left, right;
			for(int j=i; j>=0; j--){
				if(!visited[j-1]){
					left = a[j-1];
					break;
				}
			}
			for(int j=i; j<n; j++){
				if(!visited[j+1]){
					right = a[j+1];
					break;
				}
			}
			int en = left * right;
			go(w + en, cnt + 1);
			visited[i] = false;
		}
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];

	go(0, 0);
	cout<<ans<<'\n';

	return 0;
}

