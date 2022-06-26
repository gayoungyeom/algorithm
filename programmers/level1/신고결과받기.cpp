#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    //report 중복 제거
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    // 신고 횟수 초기화
    unordered_map<string, int> m;
    for(auto id: id_list) m[id] = 0;

    // 신고 횟수 카운팅
    for(auto user: report){
        stringstream ss(user);
        string x, y; 
        ss>>x>>y; //x,y에 user결과 파싱
        m[y]++;
    }    
    
    // 이용 정지 아이디 확인
    vector<string> suspend;
    for(auto it=m.begin(); it!=m.end(); it++){
        if((it->second) >= k){
            suspend.push_back(it->first);
        }
    }
    
    // 처리 메일 결과 초기화
    unordered_map<string, int> m2;
    for(auto id: id_list) m2[id] = 0;
    
    // 처리 메일 결과 카운팅
    for(auto user: report){
        stringstream ss(user);
        string x, y; 
        ss>>x>>y; //x,y에 user결과 파싱
        
        for(int i=0; i<suspend.size(); i++){
            if(y == suspend[i]){
                m2[x]++;
            }
        }
    }
    
    vector<int> answer;
    for(int i=0; i<id_list.size(); i++)
        answer.push_back(m2[id_list[i]]);
    return answer;
}
