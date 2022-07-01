#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool check(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        char cur = s[i];
        if(cur == '(' || cur == '[' || cur == '{'){
            st.push(cur);
        } else if(cur == ')' || cur == ']' || cur == '}'){
            if(st.empty()) return false;

            char x = st.top();
            st.pop();
            if(cur == ')' && x != '(') return false;
            if(cur == ']' && x != '[') return false;
            if(cur == '}' && x != '{') return false;
        } 
    }
    if(!st.empty()) return false;
    return true;
}

string rotate(string s, int x){
    string mv = s.substr(0, x);
    string tmp = "";
    for(int i=x; i<s.size(); i++)
        tmp += s[i];
    tmp += mv;
    return tmp;
}

int solution(string s) {
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        string rotated = rotate(s, i);
        if(check(rotated)) ans++;
    }
    return ans;
}
