#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int x, y;
		cin>>x>>y;

		int ans = 0;
		int dist = y - x;
		double s = sqrt(dist);

		if(s == (int)(s)){ //s가 정수이면
			ans = 2 * s - 1;
		} else {
			int left = s;
			int right = s + 1;
			double exp = pow(right, 2); //이걸 int로 하면 값이 다르게 나온다.
			int boundary = exp - left;

			if(dist < boundary)
				ans = 2 * left;
			else
				ans = 2 * left + 1;
		}

		cout<<ans<<endl;
	}
	return 0;
}

