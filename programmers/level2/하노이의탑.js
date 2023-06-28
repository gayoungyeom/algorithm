function solution(n) {
    const result = [];
    
    const move = (n, a, b) => {
        result.push([a, b]);
    }
    
    const hanoi = (n, a, b, c) => { //n개의 원판을 a에서 b로 이동
        if(n === 1) move(n, a, b); //원판이 하나일 경우 바로 a에서 b로 이동
        else {
            hanoi(n - 1, a, c, b); //가장 아래 원판 제외 c로 이동
            move(n, a, b); //가장 아래 원판을 b로 이동
            hanoi(n - 1, c, b, a); //나머지를 b로 이동
        }
    }
    
    hanoi(n, 1, 3, 2);
    
    return result;
}

