#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

bool isNum(int first, int last, int num){
	if(first > last) return false;
	else{
		int mid = (first + last) / 2;
		if(num == arr[mid]) return true;
		else if(num < arr[mid])
			return isNum(first, mid - 1, num);
		else
			return isNum(mid + 1, last, num);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, num;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];

	sort(arr, arr + n);

	cin>>m;
	for(int i=0; i<m; i++){
		cin>>num;
		cout<<isNum(0, n-1, num)<<'\n';
	}

	return 0;
}

