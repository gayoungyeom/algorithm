def solution(citations):
    n = len(citations)
    citations.sort()
    for idx, val in enumerate(citations):
        if val >= n - idx:
            return n - idx            
    return 0
