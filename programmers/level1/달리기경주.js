function solution(players, callings) {
    const ranks = new Map();
    for(let i = 0; i < players.length; i++){
        ranks.set(players[i], i);
    }
    
    for(let i = 0; i < callings.length; i++){
        const cur = ranks.get(callings[i]);
        ranks.set(players[cur], cur - 1);
        ranks.set(players[cur-1], cur);  
        [players[cur], players[cur-1]] = [players[cur-1], players[cur]];
    }
    
    return players;
}
