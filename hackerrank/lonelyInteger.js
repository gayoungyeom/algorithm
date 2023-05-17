const MAX = 101;
function lonelyinteger(a) {
    const n = a.length;
    let count = [...Array(MAX).fill(0)];
    for(const num of a){
        count[num]++;
    }
    return count.findIndex(v => v === 1);
}

