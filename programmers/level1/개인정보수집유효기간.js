function solution(today, terms, privacies) {
    const [todayYear, todayMonth, todayDay] = today.split('.').map(Number);
    
    const termsObj = {};
    for(let i = 0; i < terms.length; i++){
        const [type, expire] = terms[i].split(' ');
        termsObj[type] = +expire;
    }
    
    const keep = [];
    for(let i = 0; i < privacies.length; i++){
        const [date, type] = privacies[i].split(' ');
        const [year, month, day] = date.split('.').map(Number);
        
        let result = [year, month, day];
        const period = termsObj[type];
        
        result[1] += period;
        result[0] += ~~(result[1] / 12);
        result[1] %= 12;
        if(result[1] === 0) {
            result[0] -= 1;
            result[1] = 12;
        }
        
        //result 하루 전날까지 보관 가능
        if(todayYear < result[0]){
            keep.push(i + 1);
        } else if(todayYear === result[0]){
           if(todayMonth < result[1]){
               keep.push(i + 1);
           } else if(todayMonth === result[1]){
               if(todayDay < result[2]){
                    keep.push(i + 1);
               }
           }
        }
    }
    
    const ans = [];
    for(let i = 1; i <= privacies.length; i++){
        if(!keep.includes(i)) ans.push(i);
    }    
    return ans;
}
