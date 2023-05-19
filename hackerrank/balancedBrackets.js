const TRUE = "YES";
const FALSE = "NO";

function isBalanced(s) {
    const stack = [];
    
    for(let i = 0; i < s.length; i++){
        if(s[i] === '(' || s[i] === '{' || s[i] === '['){
            stack.push(s[i]);
        } else{
            if(stack.length === 0) return FALSE;
            
            const x = stack.pop();
            if(x === '(' && s[i] !== ')') return FALSE;
            if(x === '{' && s[i] !== '}') return FALSE;
            if(x === '[' && s[i] !== ']') return FALSE;
        }
    }

    if(stack.length !== 0) return FALSE;
    return TRUE;
}
