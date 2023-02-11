const NUMCNT = 7;

function solution(lottos, win_nums) {
    const minCnt = lottos.filter(lotto => win_nums.includes(lotto)).length;
    const maxCnt = minCnt + lottos.filter(lotto => lotto === 0).length;
    
    const minRank = NUMCNT - minCnt < NUMCNT ? NUMCNT - minCnt : 6;
    const maxRank = NUMCNT - maxCnt < NUMCNT ? NUMCNT - maxCnt : 6;

    return [maxRank, minRank];
}
