def solution(id_list, report, k):
    report = list(set(report))
    
    # 유저별 신고 횟수 초기화
    cnt = {}
    for i in id_list:
        cnt[i] = 0
        
    # 신고 횟수 카운팅
    for r in report:
        x, y = r.split(" ")
        cnt[y] += 1
  
    # 이용 정지 아이디 확인
    suspend = []
    for key, val in cnt.items():
        if(val >= k):
            suspend.append(key)
    
    # 처리 메일 횟수 초기화
    email = {}
    for i in id_list:
        email[i] = 0
    
    # 처리 메일 횟수 카운팅    
    for r in report:
        x, y = r.split(" ")
        if(y in suspend):
            email[x] += 1
            
    answer = []
    for key, val in email.items():
        answer.append(val)
    return answer
