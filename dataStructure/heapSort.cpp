#include <iostream>
using namespace std;

void HeapSort(int a[], int size); //MaxHeap
void rebuildHeap(int a[], int root, int size);

int main(){
	int a[] = {6, 5, 2, 4, 1};
	int size = 5;

	HeapSort(a,size);

	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";

	return 0;
}

void HeapSort(int a[], int n){
	//배열을 힙으로 만든다
	for(int root=n/2-1; root>=0; root--){
		rebuildHeap(a, root, n);
	}
	int heap_size = n;
	for(int last=n-1; last>0; last--){
		int temp = a[0];
		a[0] = a[last];
		a[last] = temp;
		heap_size--;
		rebuildHeap(a, 0, heap_size);
	}
}

void rebuildHeap(int a[], int root, int n){
	int x = a[root];
	int current = root;
	while(2*current+1 < n){ //루트의 왼쪽 섭트리가 n보다 작음 즉, 힙의 전체 원소
		int leftChild = 2*current+1; //왼쪽 인덱스
		int rightChild = leftChild+1; //오른쪽 인덱스
		int largerChild;
		if((rightChild <n) && (a[rightChild] > a[leftChild])) //큰 원소 판단
			largerChild = rightChild;
		else
			largerChild = leftChild;
		if(x < a[largerChild]){
			a[current] = a[largerChild];
			current = largerChild;
		}
		else
			break;
	}
	a[current] = x;

}

