const LOGIN = {
    SUCCESS: "login",
    INVALID: "wrong pw",
    ERROR: "fail"
}

//1. includes
function solution(id_pw, db) {
    const [id, pw] = id_pw;
    const result = db.map(d => id === d[0] ? pw === d[1] ? LOGIN.SUCCESS : LOGIN.INVALID : LOGIN.ERROR);
    
    if(result.includes(LOGIN.SUCCESS)) return LOGIN.SUCCESS;
    if(result.includes(LOGIN.INVALID)) return LOGIN.INVALID;
    return LOGIN.ERROR;
}

//2. Map
function solution(id_pw, db) {
    const [id, pw] = id_pw;
    const map = new Map(db);
    return map.has(id) ? map.get(id) ===  pw ? LOGIN.SUCCESS : LOGIN.INVALID : LOGIN.ERROR;
}
