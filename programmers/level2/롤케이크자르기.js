function solution(topping) {
    let count = 0;
    const n = topping.length;
    
    const accA = [1], accB = [1];
    const setA = new Set(), setB = new Set();
    setA.add(topping[0]);
    setB.add(topping[n - 1]);
    
    for(let i = 1; i < n; i++){
        accA.push(setA.has(topping[i]) ? accA[i - 1] : accA[i - 1] + 1);
        setA.add(topping[i]);
    }
    for(let i = n - 2; i >= 0; i--){
        accB.push(setB.has(topping[i]) ? accB[n - i - 2] : accB[n - i - 2] + 1);
        setB.add(topping[i]);
    }
    
    accB.reverse();

    for(let i = 0; i < n - 1; i++){
        if(accA[i] === accB[i + 1]){
            count++;
        }
    }
    
    return count;
    
}
