function solution(record) {
    const result = [];
    const users = {};
    
    for(const rc of record){
        const [type, id, name] = rc.split(' ');
        
        if(type !== "Leave") users[id] = name;
        result.push([id, type]);                
    }
    
    const message = [];
    for(const rs of result){
        const [id, type] = rs;
        
        if(type === "Enter") message.push(`${users[id]}님이 들어왔습니다.`);
        else if(type === "Leave") message.push(`${users[id]}님이 나갔습니다.`);
    }
    
    return message;
}
