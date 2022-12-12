function solution(my_string) {
    return [...my_string].map(s => s.match(/[A-Z]/) ? s.toLowerCase() : s.toUpperCase()).join('');
}
