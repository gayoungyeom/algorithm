function solution(s) {
    const len = s.length;
    const mid = ~~(len / 2);
    return len % 2 ? s[mid] : s[mid-1] + s[mid];
}
