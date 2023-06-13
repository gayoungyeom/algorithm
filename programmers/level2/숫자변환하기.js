//DP & x -> y(일관된 y - x 수행 시간으로 성공)
function solution(x, y, n) {
    let d = [...Array(y + 1).fill(Infinity)]; //d[i]: x에서 i를 만들 수 있는 최소 연산 횟수
    d[x] = 0;
    
    for(let i = x; i <= y; i++){
        if(i - n >= x) d[i] = Math.min(d[i], d[i - n] + 1);
        if(i % 2 === 0 && i / 2 >= x) d[i] = Math.min(d[i], d[i / 2] + 1);
        if(i % 3 === 0 && i / 3 >= x) d[i] = Math.min(d[i], d[i / 3] + 1);
    }
    
    return d[y] === Infinity ? -1 : d[y];
}

//BFS & y -> x (불필요한 함수 호출이 제거되어 더 빠름, 이지만 shift 연산으로 시간 초과)
// function solution(x, y, n) {
//     let result = -1;
//     const q = [];
//     q.push([y, 0]);
    
//     while(q.length !== 0){
//         const [value, step] = q.shift();
//         if(value <= x) {
//             if(value === x) result = step;
//             break;
//         }
        
//         if(value - n >= x) q.push([value - n, step + 1]);
//         if(value % 2 === 0 && value / 2 >= x) q.push([value / 2, step + 1]);
//         if(value % 3 === 0 && value / 3 >= x) q.push([value / 3, step + 1]);
//     }
 
//     return result;
// }

//재귀 & x -> y (시간 초과)
// function solution(x, y, n) {
//     let result = Infinity;
    
//     const go = (cur, step) => {
//         if(cur === y){
//             result = Math.min(result, step);
//             return;
//         }
        
//         if(cur > y) return;
        
//         go(cur + n, step + 1);
//         go(cur * 2, step + 1);
//         go(cur * 3, step + 1);
//     }
    
//     go(x, 0);
    
//     return result === Infinity ? -1 : result;
// }
