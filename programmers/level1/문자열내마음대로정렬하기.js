function solution(strings, n) {
    return strings.sort((a, b) => a[n] === b[n] ? a > b ? 1 : -1 : a[n] > b[n] ? 1 : -1);
}

function solution(strings, n) {
    return strings.sort((a, b) => a[n] === b[n] ? a.localeCompare(b) : a[n].localeCompare(b[n]));
}
