//1. 일단 모든 score를 순서대로 rankers에 push
//2. rankers 정렬 -> 인덱스가 k-1인 값이 발표 점수
function solution(k, score) {
    let rankers = [];
    let points = [];

    for(let i = 0; i < score.length; i++){
        rankers.push(score[i]);
        rankers.sort((a, b) => b - a);

        const len = rankers.length;
        points.push(rankers[len < k ? len - 1 : k - 1]);
    }
    
    return points;
}
