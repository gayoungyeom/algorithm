function gridChallenge(grid) {
    const n = grid.length;
    const rowSorted = grid.map(row => [...row].sort());
    
    let flag = true;
    for(let i = 0; i < n; i++){
        const columns = [];
        for(let j = 0; j < n; j++){
            columns.push(rowSorted[j][i]);
        }
        
        const colSorted = columns.slice().sort();
        
        for(let j = 0; j < n; j++){
            if(columns[j] !== colSorted[j]){
                flag = false;
            }
        }
        
        if(!flag) return "NO";
    }
    return "YES";    
}
