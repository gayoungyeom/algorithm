function solution(n, k, enemy) {
    let start = 0;
    let end = enemy.length;
    
    while(start <= end){
        const mid = ~~((start + end) / 2);
        
        const curEnemy = enemy.slice(0, mid).sort((a, b) => b - a);
        
        let dead = 0; //무적권을 최대한 사용 후 남은 적의 수 (= 죽은 병사 수)
        for(let i = k; i < curEnemy.length; i++){
            dead += curEnemy[i];
        }
        
        if(n >= dead){
            start = mid + 1;
        } else{
            end = mid - 1;
        }
    }
    
    return end;
}
