const rspWin = {
    "2": "0",
    "0": "5",
    "5": "2",
}

function solution(rsp) {
    return [...rsp].map(v => rspWin[v]).join('');
}
