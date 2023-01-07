const SPLIT_POINT = -1;

//1. 수동 split + parseInt
function solution(my_string) {
    const numList = [...my_string].map(s => isNaN(s) ? SPLIT_POINT : s).join('').split(SPLIT_POINT);
    return numList.filter(n => n !== "").reduce((sum, cur) => sum + parseInt(cur), 0);
}

//2. 수동 split + Number
function solution(my_string) {
    const numList = [...my_string].map(s => isNaN(s) ? SPLIT_POINT : s).join('').split(SPLIT_POINT);
    return numList.reduce((sum, cur) => sum + Number(cur), 0);
}

// 3. 정규식 split + Number
function solution(my_string) {
    return my_string.split(/\D+/).reduce((sum, cur) => sum + Number(cur), 0);
}

/*
parseInt("") //NaN
Number("") //0
*/
