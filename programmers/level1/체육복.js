//clothes[i]: i번 학생이 가지고 있는 체육복의 개수
function solution(n, lost, reserve) {
    const clothes = [...Array(n).fill(1)];
    reserve.forEach(v => clothes[v-1] += 1);
    lost.forEach(v => clothes[v-1] -= 1);
                    
    clothes.forEach((c, i) => {
        if(c === 2){
            if(clothes[i-1] === 0){
                clothes[i-1] += 1;
                clothes[i] -= 1;
            } else if(clothes[i+1] === 0){
                clothes[i+1] += 1;
                clothes[i] -= 1;
            }
        }
    });

    return clothes.filter(c => c).length;
}
