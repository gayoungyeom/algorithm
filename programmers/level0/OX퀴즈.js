function solution(quiz) {
    const ans = [];
    const cal = quiz.map(q => q.split(" "));
    
    for(let c of cal){
        const [x, op, y, _, z] = c;
        if(op === "+") Number(x) + Number(y) === Number(z) ? ans.push("O") : ans.push("X");
        if(op === "-") Number(x) - Number(y) === Number(z) ? ans.push("O") : ans.push("X");
    }
    
    return ans;
}
