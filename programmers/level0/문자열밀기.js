//1. 배열 회전과 같은 방식 (unshift)
function solution(A, B) {
    let arr = [...A];
    for(let i = 0; i < A.length; i++){
        if(arr.join('') === B) return i;
        arr.unshift(arr.pop());       
    }
    return -1;
}

//2. indexOf 기능을 제대로 활용한 방식인듯..!
function solution(A, B){
    return (B + B).indexOf(A);
}

