const BURGER = "1231";
const BURGER_NUM = BURGER.length;

function solution(ingredient) {
    let cnt = 0;
    let s = [];
    
    for(let i = 0; i < ingredient.length; i++){
        s.push(ingredient[i]);  
        
        let four = BURGER_NUM;
        const burger = s.slice(-BURGER_NUM).join('') === BURGER;

        if(burger){
            cnt++;
            while(four--){
                s.pop();
            }
        }
    }
    
    return cnt;
}
