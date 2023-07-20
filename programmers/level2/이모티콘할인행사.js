function solution(users, emoticons) {
    const discounts = [];
     
    const dfs = (tmp) => { //이모티콘 할인률 선택
        if(tmp.length === emoticons.length){
            discounts.push([...tmp]);
            return;
        }
        
        for(let i = 1; i <= 4; i++){
            tmp.push(i);
            dfs(tmp);
            tmp.pop();
        }
    }
    
    dfs([]);
    
    let ans = [0, 0]; //[가입자수, 판매액]
    
    for(const discount of discounts){
        let plus = 0; //가입자수
        let pay = 0; //판매액

        for(const user of users){
            const [percent, price] = user;
            
            let curPay = 0;
            for(let i = 0; i < emoticons.length; i++){
                if(discount[i] * 10 >= percent){ //이모티콘 구매
                    curPay += (emoticons[i] * ((10 - discount[i]) / 10));
                }
            }
            
            if(curPay >= price){ //플러스 가입
                plus++;
                curPay = 0;
            }
            
            pay += curPay;
        }
        
        if(ans[0] < plus){
            ans = [plus, pay];
        } else if(ans[0] === plus){
            ans[1] = Math.max(ans[1], pay);
        }
    }

    return ans;
}
