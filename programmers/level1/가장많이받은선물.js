function solution(friends, gifts) {
    const n = friends.length;
    const giftArr = Array.from(Array(n), () => Array(n).fill(0));

    //주고 받은 선물
    for(const gift of gifts){
        const [a, b] = gift.split(' ');
        const ai = friends.indexOf(a);
        const bi = friends.indexOf(b);
        giftArr[ai][bi]++;
    }
    
    //선물 지수
    const giftIndex = [...Array(n).fill(0)];
    
    for(let i = 0; i < n; i++){
        let give = 0, take = 0;
        for(let j = 0; j < n; j++){
            give += giftArr[i][j];        
            take += giftArr[j][i];
        }
        giftIndex[i] = give - take;
    }
    
    //다음달에 받을 선물
    const nextGift = [...Array(n).fill(0)];
    
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            const a = giftArr[i][j]
            const b = giftArr[j][i];
            
            if(a < b){
                nextGift[j]++;
            } else if(a > b){
                nextGift[i]++;
            } else{
                //선물 지수 체크
                const agi = giftIndex[i];
                const bgi = giftIndex[j];
                
                if(agi < bgi){
                    nextGift[j]++;
                } else if(agi > bgi){
                    nextGift[i]++;
                }
            }
            
        }
    }
    
    return Math.max(...nextGift);
}
