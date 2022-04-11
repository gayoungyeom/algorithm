#include <iostream>
#include <cstring>
using namespace std;

int n;
string s;
int f[1001];

void dp(int idx){
	if(idx == n-1) return;
	if(idx >= n) return;

	char cur = s[idx];
	if(cur == 'B'){
		for(int i=idx+1; i<n; i++){
			if(s[i] == 'O'){
				int diff = i - idx;
				int tmp = f[idx]+diff*diff;
				if(f[i] == -1 || f[i] > tmp){
					f[i] = tmp;
					dp(i);
				}
			}
		}
	} else if(cur == 'O'){
		for(int i=idx+1; i<n; i++){
			if(s[i] == 'J'){
				int diff = i - idx;
				int tmp = f[idx]+diff*diff;
				if(f[i] == -1 || f[i] > tmp){
					f[i] = tmp;
					dp(i);
				}
			}
		}
	} else{ //J
		for(int i=idx+1; i<n; i++){
			if(s[i] == 'B'){
				int diff = i - idx;
				int tmp = f[idx]+diff*diff;
				if(f[i] == -1 || f[i] > tmp){
					f[i] = tmp;
					dp(i);
				}
			}
		}
	}
}

int main(){
	cin>>n;
	cin>>s;
	memset(f, -1, sizeof(f));
	f[0] = 0;
	dp(0);
	cout<<f[n-1]<<'\n';
	return 0;
}

