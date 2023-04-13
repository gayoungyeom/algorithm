function solution(n, m, section) {
    let lastPaint = 0; //페인트가 칠해진 마지막 위치
    let cnt = 0;
    for(const cur of section){
        if(cur > lastPaint){ //아직 칠해지지 않은 부분이 있는 경우
            lastPaint = cur + m - 1;
            cnt++;
        }
    }
    return cnt;
}
