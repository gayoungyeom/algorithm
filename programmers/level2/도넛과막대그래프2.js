//inOut을 객체로 관리
function solution(edges) {
    const result = [0, 0, 0, 0]; //[생성, 도넛, 막대, 8자]
    
    const inOut = {}; // [in, out]
    
    for(const edge of edges){
        const [a, b] = edge;
        
        if(inOut[a]) inOut[a][1]++;
        else inOut[a] = [0, 1];
        
        if(inOut[b]) inOut[b][0]++;
        else inOut[b] = [1, 0];
    }
    
    //생성 정점 찾기
    const point = Object.values(inOut).findIndex(v => v[0] === 0 && v[1] >= 2) + 1;
    result[0] = point;
    
    //생성 정점에서 가는 간선 빼기
    for(const edge of edges){
        const [a, b] = edge;
        if(a === point) inOut[b][0]--;
    }
   
    for(const [node, inOutCnt] of Object.entries(inOut)){
        if(node === point) continue; //생성 정점 제외

        const [inCnt, outCnt] = inOutCnt;
        
        if((inCnt === 0 && (outCnt === 0 || outCnt === 1))) result[2]++; //막대
        if(inCnt === 2 && outCnt === 2) result[3]++; //8자
    }
    
    result[1] = inOut[point][1] - result[2] - result[3]; //도넛
    
    return result;
}
