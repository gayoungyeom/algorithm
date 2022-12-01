const vowel = ['a', 'e', 'i', 'o', 'u'];

function solution(my_string) {
    return [...my_string].filter(s => !vowel.includes(s)).join('');
}
