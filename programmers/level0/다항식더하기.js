const checkOp = (arr, i) => i === 0 ? "+" : arr[i-1];

const sum = (arr) => arr.reduce((s, c) => s + c, 0);

function solution(polynomial) {
    const arr = polynomial.split(" ");
    const x = [];
    const c = [];
    
    for(let i = 0; i < arr.length; i++){
        const cur = arr[i];
        
        if(!isNaN(cur)){ //상수항인 경우
            const op = checkOp(arr, i);
            
            if(op === "+") c.push(Number(cur));
            else c.push(Number(-cur));
        }
        
        if(cur.includes("x")){ //1차항인 경우
            const num = Number(cur.slice(0, cur.length-1))  || 1;
            const op = checkOp(arr, i);
            
            if(op === "+") x.push(num);
            else x.push(-num);
        }
    }
    
    const sumX = sum(x);
    const sumC = sum(c);
    
    if(sumX === 0) return `${sumC}`;
    if(sumC === 0) return `${sumX === 1 ? '' : sumX}x`;
    return `${sumX === 1 ? '' : sumX}x + ${sumC}`;
}
