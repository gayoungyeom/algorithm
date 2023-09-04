function solution(user_id, banned_id) {
    const checkId = (userId, bannedId) => {
        if(userId.length !== bannedId.length) return false;
        for(let i = 0; i < bannedId.length; i++){
            if(bannedId[i] !== '*'){
                if(bannedId[i] !== userId[i]){
                    return false;
                }
            }
        }
        return true;
    }
    
    //불량사용자에 매핑되는 아이디 리스트 구하기
    const restricts = [];
    for(const bannedId of banned_id){
        const restrict = [];
        
        for(const userId of user_id){
            if(checkId(userId, bannedId)){
                restrict.push(userId);
            }
        }
        restricts.push(restrict);
    }
    
    let visited = Array.from(Array(banned_id.length), () => Array(user_id.length).fill(false));
    const result = [];
    
    //dfs로 가능한 경우의 수 구하기        
    const dfs = (cur, tmp) => {
        if(tmp.length === banned_id.length){
            const s = new Set();
            for(const t of tmp){
                s.add(t);
            }
            if(s.size === banned_id.length) result.push([...s]);
            return;
        }
        
        for(let i = 0; i < restricts[cur].length; i++){
            if(!visited[cur][i]){
                tmp.push(restricts[cur][i]);
                visited[cur][i] = true;
                dfs(cur + 1, tmp);
                visited[cur][i] = false;
                tmp.pop();
            }
        }
    }
    
    dfs(0, []);
    
    //set으로 중복 제거
    const isArrEqual = (arr1, arr2) => {
        if(arr1.length !== arr2.length) return false;
        const set1 = new Set(arr1);
        for(const item of arr2){
            if(!set1.has(item)){
                return false;
            }
        }
        return true;
    }

    const getUniqueArr = (arr) => {
        const unique = [];
        for(const item of arr){
            if(!unique.some(uniqueItem => isArrEqual(uniqueItem, item))){
                unique.push(item);
            }
        }
        return unique;
    }

    return getUniqueArr(result).length;
}
