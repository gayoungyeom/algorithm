#include <iostream>
using namespace std;
 
int main(){
    int test_case;
    int T;
    cin>>T;
    int num[T];
    int multi[10]={0,0,0,0,0,0,0,0,0,0};
 
    for(test_case = 0; test_case < T; test_case++){
        cin>>num[test_case];
    }
 
    for(test_case = 0; test_case < T; test_case++){
        for(int i=0; i<10; i++) multi[i]=0;
        int tc=num[test_case];
        while(tc>0){
            multi[tc%10]++;
            tc=tc/10;
        }
        int count=0;
 
        for(int i=0; i<10; i++){
            if(multi[i]!=0) count++;
        }
 
        cout<<"#"<<test_case+1<<" "<<count<<endl;
    }
 
    return 0;
}
