function superDigit(n, k) {
    const init = [...n].reduce((a, b) => parseInt(a) + parseInt(b), 0) * k; //repeat(k)보다 낮은 시간복잡도
    
    let p = init;
    while(p > 9){
        const digit = [...p.toString()].reduce((a, b) => parseInt(a) + parseInt(b), 0);
        p = digit;
    }
    return p;
}
