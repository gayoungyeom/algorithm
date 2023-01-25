function solution(num) {
    let cnt = 0;
    while(1){
        if(num === 1) return cnt;
        if(cnt > 500) return -1;
        
        num = num % 2 ? num * 3 + 1 : num / 2;
        cnt++;
    }
}
