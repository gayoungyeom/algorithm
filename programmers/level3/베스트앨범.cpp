#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> genres;
vector<int> plays;

map<string, int> genresCnt;
map<int, int> playsCnt;

int cmp(pair<string, int>& v1, pair<string, int>& v2){
	return v1.second > v2.second;
}

int cmp2(pair<int, int>& v1, pair<int, int>& v2){
	return v1.second > v2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    //1. key-value 구조화
    for(unsigned int i=0; i<genres.size(); i++){
    	string genre = genres[i];
    	if(genresCnt.count(genre))
    		genresCnt[genre] += plays[i];
    	else
    		genresCnt.insert(make_pair(genre, plays[i]));
    }

    //2. map -> vector 치환 후 value 기준으로 내림차순 정렬
    vector<pair<string, int>> v;
    for(auto it=genresCnt.begin(); it!=genresCnt.end(); it++)
    	v.push_back(make_pair(it->first, it->second));
    sort(v.begin(), v.end(), cmp);


    //3.
    for(unsigned int i=0; i<v.size(); i++){
    	//3-1
    	for(unsigned int j=0; j<genres.size(); j++){
    		if(v[i].first == genres[j])
    			playsCnt[j] = plays[j];
    	}

    	//3-2
    	vector<pair<int, int>> v2;
        for(auto it=playsCnt.begin(); it!=playsCnt.end(); it++)
        	v2.push_back(make_pair(it->first, it->second));
        sort(v2.begin(), v2.end(), cmp2);

        //3-3
        int cnt = 0;
        for(unsigned int j=0; j<v2.size(); j++){
        	if(cnt > 1) break;
        	answer.push_back(v2[j].first);
        	cnt++;
        }
        playsCnt.clear();
    }

    return answer;
}
