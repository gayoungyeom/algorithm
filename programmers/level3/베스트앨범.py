def solution(genres, plays):
    answer = []
    
    genresCnt = {}
    for i in range(len(genres)):
        genre = genres[i]
        if genre in genresCnt:
            genresCnt[genre] += plays[i]
        else:
            genresCnt[genre] = plays[i]

    genresCnt = dict(sorted(genresCnt.items(), key=lambda item: item[1], reverse=True))

    for genre in genresCnt.keys():
        playsCnt = {}
        for idx, val in enumerate(genres):
            if genre == val:
                 playsCnt[idx] = plays[idx]
        
        playsCnt = dict(sorted(playsCnt.items(), key=lambda item: item[1], reverse=True))

        i = 0
        for key, val in playsCnt.items():
            if i > 1:
                break
            answer.append(key)
            i += 1
        playsCnt.clear()
        
    return answer
