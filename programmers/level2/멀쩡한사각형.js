//최대공약수
function solution(w, h) {
    const gcd = (a, b) => b === 0 ? a : gcd(b, a % b);
    
    const g = gcd(w, h);
    const n = w / g;
    const m = h / g;
    
    let cut = (n + m - 1) * g;
    return w * h - cut;
}

//원점과 (w, h)를 지나는 함수 활용
//const r = h / w -> 기울기(javascript 나눗셈 정확하지 않아서 tc6 fail)
function solution(w, h) {
    let cut = 0; 
    for(let x = 1; x <= w; x++){
        const py = (h * (x - 1)) / w; //r * (x - 1)
        const y = (h * x) / w; //r * x
        cut += (Math.ceil(y) - Math.floor(py)); //기울기 아래 있는 박스 - 기울기가 닿지 않는 박스
    }

    return w * h - cut;
}
