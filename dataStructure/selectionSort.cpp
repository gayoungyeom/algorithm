#include <iostream>
using namespace std;

void selectionsort(int* a, int n); //O(n^2)
void swap(int* a, int* b);

int main(){
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	selectionsort(a, n);

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";

	return 0;
}

void selectionsort(int* a, int n){
	for(int i=n-1; i>0; i--){
		int maxIndex=0;
		for(int j=1; j<=i; j++){
			if(a[maxIndex] < a[j]) maxIndex=j;
		}
		swap(a[maxIndex],a[i]);
	}
}

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
