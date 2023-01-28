//JS에서는 존재하지 않는 값에 접근할 때 undefined를 반환하니까 이게 되네..
function solution(arr) {
    return arr.filter((a, i) => a !== arr[i + 1]);
}
