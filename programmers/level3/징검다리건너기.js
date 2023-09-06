//이진탐색 (파라메트릭 서치)
function solution(stones, k) {
    let begin = 1;
    let end = 200000000;
    
    while(begin <= end){
        const mid = ~~((begin + end) / 2);
        
        let jump = 0;
        for(const stone of stones){
            if(stone <= mid) jump++;
            else jump = 0;
            
            if(jump >= k) break;
        }
        
        if(jump >= k){ //건널 수 없는 경우
            end = mid - 1;
        } else{ //건널 수 있는 경우
            begin = mid + 1;
        }
    }
    
    return begin;
}

//최댓값 중 최소를 구하는 로직을 정렬(최소힙)로 처리 -> js한계로 효율성 FAIL
function solution(stones, k) {
    const q = [];
    for(let i = 0; i < k; i++){
        q.push([stones[i], i]);
    }
    q.sort((a, b) => a[0] - b[0]);
    
    let result = q[k - 1][0];

    for(let i = k; i < stones.length; i++){
        q.push([stones[i], i]);
        q.sort((a, b) => a[0] - b[0]);
        
        while(q[q.length - 1][1] < i - k + 1){
            q.pop();
        }
        
        result = Math.min(result, q[q.length - 1][0]);
    }

    return result;
}

// 효율성 FAIL
function solution(stones, k) {
    let result = Infinity;
    
    //k구간 내 최댓값 중 최소
    for(let i = 0; i <= stones.length - k; i++){
        const q = [];
        for(let j = i; j < i + k; j++){
            q.push([stones[j], j]);
        }
        q.sort((a, b) => b[0] - a[0]);
        
        result = Math.min(result, q[0][0]);
    }
    
    return result;
}
