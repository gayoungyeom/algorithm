#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Member{
	int age;
	string name;
};

bool compare(const Member &a, const Member &b){
	return a.age < b.age;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	cin>>n;

	vector<Member> v(n);
	for(int i=0; i<n; i++)
		cin>>v[i].age>>v[i].name;

	stable_sort(v.begin(), v.end(), compare);

	for(int i=0; i<n; i++)
		cout<<v[i].age<<" "<<v[i].name<<'\n';
}

