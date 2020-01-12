#include <iostream>
#include <stack>
using namespace std;

int A[1001];
int length[1001];
int log[1001];

int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>A[i];

	stack<int> s;
	int answer = 1;
	int logIndex = 1;

	length[1] = 1;
	log[1] = 1;
	for(int i=2; i<=n; i++){
		int max = 0;
		int maxIndex = 1;
		for(int j=i-1; j>0; j--){
			if(A[j]<A[i] && length[j]>max){
				max = length[j];
				maxIndex = j;
			}
		}
		length[i] = max + 1;
		log[i] = maxIndex;
		if(length[i] > answer){ //answer = max in length
			answer = length[i];
			logIndex = i;
		}
	}

	s.push(A[logIndex]);
	for(int i=1; i<=answer-1; i++){
		s.push(A[log[logIndex]]);
		logIndex = log[logIndex];
	}

	cout<<answer<<endl;
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}
