function solution(cards1, cards2, goal) {
    let c1 = 0, c2 = 0; //각 카드의 인덱스
    
    let result = "";
    for(let i = 0; i < goal.length; i++){
        const target = goal[i];
        if(cards1[c1] === target) {
            c1++;
            result += target;
        }
        if(cards2[c2] === target) {
            c2++;
            result += target;
        }
    }
    
    return result === goal.join('') ? "Yes" : "No";
}
