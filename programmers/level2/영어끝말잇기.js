function solution(n, words) {
    let cur = 0;
    let word = words[cur];
    const set = new Set();
    set.add(words[cur]);
    
    for(let i = 1; i < words.length; i++){
        cur = (cur + 1) % n;
        if(word[word.length - 1] !== words[i][0] || set.has(words[i])){
            return [cur + 1, ~~(i / n) + 1];
        } 
        word = words[i];
        set.add(word);
    }
    
    return [0, 0];
}
