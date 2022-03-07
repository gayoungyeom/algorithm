#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, s;
	cin>>n>>s;

	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];

	//1. 절반으로 나누기
	int m = n/2; //뒷 부분
	n = n - m; //앞 부분

	//2. 각각에 대해 모든 부분수열 나열하기 <- 비트마스크로 순열 표현
	vector<int> first(1<<n);
	for(int i=0; i<(1<<n); i++){
		for(int k=0; k<n; k++){
			if(i&(1<<k))
				first[i] += a[k];
		}
	}

	vector<int> second(1<<m);
	for(int i=0; i<(1<<m); i++){
		for(int k=0; k<m; k++){
			if(i&(1<<k))
				second[i] += a[k+n];
		}
	}

	//3. 정렬
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());

	//4. 왼쪽과 오른쪽 합 더하기
	n = (1<<n);
	m = (1<<m);
	int i = 0;
	int j = 0;
	long long ans = 0; //int로 하면 틀림
	while(i < n && j < m){
		if(first[i] + second[j] < s){
			i++;
		} else if(first[i] + second[j] == s){
			long long c1 = 1;
			long long c2 = 1;
			i++;
			j++;
			while(i < n && first[i] == first[i-1]){
				c1++;
				i++;
			}
			while(j < m && second[j] == second[j-1]){
				c2++;
				j++;
			}
			ans += c1*c2;
		} else{
			j++;
		}
	}

	if(s == 0) ans--;
	cout<<ans<<'\n';

	return 0;
}

