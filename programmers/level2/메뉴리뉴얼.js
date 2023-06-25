function solution(orders, course) {
    const menus = {};
    
    const go = (n, order, cur, tmp) => {
        if(tmp.length === n){
            const menu = tmp.join('');
            if(menus[menu]) menus[menu]++;
            else menus[menu] = 1;
            return;
        }
        
        for(let i = cur; i < order.length; i++){
            tmp.push(order[i]);
            go(n, order, i + 1, tmp);
            tmp.pop();
        }
    }
    
    for(let i = 0; i < course.length; i++){
        const n = course[i];
        for(const order of orders){
            const sortedOrder = [...order].sort();
            go(n, sortedOrder, 0, []);
        }        
    }
    
    const sorted = Object.entries(menus).sort((a, b) => b[1] - a[1]);
    const top = Array.from(Array(11), () => []);
    
    for(const [name, count] of sorted){
        if(count < 2) continue;
    
        if(top[name.length].length !== 0){
            if(top[name.length][0][1] === count){
                top[name.length].push([name, count]);
            } 
        } else{
            top[name.length].push([name, count]);
        }
    }
    
    return top.flat().map(v => v[0]).sort();
}
