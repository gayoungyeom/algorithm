#include <iostream>
using namespace std;

void insertionSort(int a[], int size);

int main(){
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	insertionSort(a, n);

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";

	return 0;
}

void insertionSort(int a[], int n){
	int temp, j;
	for(int i=1; i<n; i++){
		temp=a[i];
		for(j=i-1; j>=0; j--){
			if(temp<a[j])
				a[j+1]=a[j];
			else
				break;
		}
		a[j+1]=temp;
	}
}
