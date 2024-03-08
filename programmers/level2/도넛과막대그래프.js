//const maxSize = Math.max(...edges.flat())은 왜 런타임 에러나지
function solution(edges) {
    const result = [0, 0, 0, 0]; //[생성, 도넛, 막대, 8자]
    
    const maxA = edges.sort((a, b) => b[0] - a[0])[0][0];
    const maxB = edges.sort((a, b) => b[1] - a[1])[0][1];
    const maxSize = Math.max(maxA, maxB) + 1;
    const inOut = Array.from(Array(maxSize), () => [0, 0]); //[in, out]
    
    for(const edge of edges){
        const [a, b] = edge;
        inOut[a][1]++;
        inOut[b][0]++;
    }
    
    //생성 정점 찾기
    const point = inOut.slice(1).findIndex(v => v[0] === 0 && v[1] >= 2) + 1;
    result[0] = point;
    
    //생성 정점에서 가는 간선 빼기
    for(const edge of edges){
        const [a, b] = edge;
        if(a === point) inOut[b][0]--;
    }
    
    for(let i = 1; i < maxSize; i++){
        if(i === point) continue; //생성 정점 제외
        
        const [inCnt, outCnt] = inOut[i];
        
        if((inCnt === 0 && (outCnt === 0 || outCnt === 1))) result[2]++; //막대
        if(inCnt === 2 && outCnt === 2) result[3]++; //8자
    }
    
    result[1] = inOut[point][1] - result[2] - result[3]; //도넛
    
    return result;
}
