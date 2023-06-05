function solution(n, t, m, p) {
    let tubeAns = '';
    let result = '';
    let num = 0;
    
    while(tubeAns.length !== t){
        result += num.toString(n);
        
        if((num % m) + 1 === p){
            tubeAns += result[num].toUpperCase();
        }
        num++;
    }
    
    return tubeAns;
}
