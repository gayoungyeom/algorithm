//1. 반복문
function solution(my_string) {
    const arr = my_string.split(" ");
    let ans = Number(arr[0]);
    let i = 1;
    while(i < arr.length){
        if(arr[i] === "+")
            ans += Number(arr[i+1]);
        if(arr[i] === "-")
            ans -= Number(arr[i+1]);
        i += 2;
    }
    return ans;
}

//2. eval -> 단, 사용을 지양해야 하는 함수
function solution(my_string) {
    return eval(my_string);
}
