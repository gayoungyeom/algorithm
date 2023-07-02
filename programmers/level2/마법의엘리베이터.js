function solution(storey) {
    let cnt = 0;
    
    while(storey > 0){
        const mod = storey % 10;
        const div = storey / 10;
        
        if(mod === 5){ //5층이면 앞의 숫자 확인
            if(Math.floor(div) % 10 < 5){ //앞의 숫자가 5보다 작으면 내려가는게 빠름
                cnt += mod;
                storey = Math.floor(div);
            } else{ //올라가는게 빠름
                cnt += (10 - mod);
                storey = Math.ceil(div);
            }
        } else if(mod < 5){
            cnt += mod;
            storey = Math.floor(div);
        } else{
            cnt += (10 - mod);
            storey = Math.ceil(div);
        }
    }
    
    return cnt;
}
