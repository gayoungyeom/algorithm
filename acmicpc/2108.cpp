#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector <pair<int, int>> v; //<값, 빈도수>

//second 기준으로 내림차순 정렬
bool compare(pair<int, int> v1, pair<int, int> v2){
	if(v1.second == v2.second){
		return v1.first < v2.first;
	}
	return v1.second > v2.second;
}

int main(){
	int n;
	cin>>n;

	int arr[n];
	double mean;
	int median, mode, range;

	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		arr[i] = x;

		//1. 산술평균
		mean += x;
		if(i == n -1) mean /= n;

		//3. 최빈값
		if(i == 0) v.push_back(make_pair(x, 1));
		else{
			bool flag = true;
			for(unsigned int j=0; j<v.size(); j++){
				if(v[j].first == x){
					v[j].second++;
					flag = false;
					break;
				}
			}
			if(flag) v.push_back(make_pair(x, 1));
		}
	}

	sort(v.begin(), v.end(), compare);

	mode = v[0].first;
	if(v[0].second == v[1].second) mode = v[1].first;

	//2. 중앙값  & 4. 범위
	sort(arr, arr + n);
	median = arr[n/2];
	range = arr[n-1] - arr[0];

	cout<<round(mean)<<endl;
	cout<<median<<endl;
	cout<<mode<<endl;
	cout<<range<<endl;

	return 0;
}

