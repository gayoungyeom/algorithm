function solution(want, number, discount) {
    const productObj = new Map();
    let ans = 0;
    
    for(let i = 0; i < discount.length; i++){
        for(const w of want){
            productObj.set(w, 0);
        };
        
        const memberDiscount = discount.slice(i, i + 10);
        for(const product of memberDiscount){
            if(productObj.has(product)){    
                productObj.set(product, productObj.get(product) + 1);;
            }  
        }
        
        const getNum = [...productObj.values()];
        let flag = true;
        for(let j = 0; j < number.length; j++){
            if(number[j] !== getNum[j]){
                flag = false;
                break;
            }
        }
        
        if(flag) ans++;
    }
    
    return ans;
}
