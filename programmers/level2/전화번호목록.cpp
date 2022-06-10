#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> m;
    for(auto p: phone_book){
    	m[p] = 1;
    }
    for(unsigned int i=0; i<phone_book.size(); i++){
    	string phone_sub = phone_book[i].substr(0, phone_book[i].size()-1);
		string num = "";
    	for(unsigned int j=0; j<phone_sub.size(); j++){
    		num += phone_sub[j];
    		if(m[num])
    			return false;
    	}
    }
    return true;
}
