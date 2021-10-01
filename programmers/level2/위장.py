def solution(clothes):
    answer = 1
    
    #구조화
    clothesCnt = {}
    for c in clothes:
        cur = c[1]
        if cur in clothesCnt:
            clothesCnt[cur] += 1
        else:
            clothesCnt[cur] = 1
    
    #조합 계산
    for val in clothesCnt.values():
        answer *= val + 1

    return answer - 1
