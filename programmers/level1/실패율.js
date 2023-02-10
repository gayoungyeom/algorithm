//1. Map 활용 -> 훨씬 빠름
function solution(N, stages) {   
    const m = new Map();
    stages.forEach(stage => m.set(stage, m.has(stage) ? m.get(stage) + 1 : 1));
   
    const fails = [];
    let totalCnt = stages.length;
    for(let stage = 1; stage <= N; stage++){
        const notClearCnt = m.get(stage) || 0;
        fails.push([notClearCnt / totalCnt, stage]);
        totalCnt -= notClearCnt;        
    }

    return fails.sort((a, b) => b[0] - a[0]).map(fail => fail[1]);
}

//2. filter 활용
function solution(N, stages) {
    const fails = [];
    
    for(let i = 1; i <= N; i++){
        const totalCnt = stages.filter(stage => stage >= i).length;
        const notClearCnt = stages.filter(stage => stage === i).length;
        fails.push([notClearCnt / totalCnt, i]);
    }
    
    return fails.sort((a, b) => b[0] - a[0]).map(fail => fail[1]);
}
