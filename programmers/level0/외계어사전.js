function solution(spell, dic) {
    const word = spell.sort().join('');
    const sorted = dic.map(d => [...d].sort().join(''));
    return sorted.includes(word) ? 1 : 2;
}
