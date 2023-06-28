function solution(m, musicinfos) {
    m = m.replace(/(C|D|F|G|A)#/g, (_, v) => v.toLowerCase());
    
    const result = [];
    
    for(const musicinfo of musicinfos){
        const [start, end, title, info] = musicinfo.split(",");
        const [startH, startM] = start.split(':').map(Number);
        const [endH, endM] = end.split(':').map(Number);
        const playTime = (endH * 60 + endM) - (startH * 60 + startM);
        
        let playInfo = info.replace(/(C|D|F|G|A)#/g, (_, v) => v.toLowerCase());
        playInfo = playInfo.padEnd(playTime, playInfo).slice(0, playTime);;
        
        for(let i = 0; i <= playInfo.length - m.length; i++){
            const cur = playInfo.slice(i, i + m.length);
            if(cur === m){
                result.push([playTime, title]);
                break;
            }
        }
    }
    
    result.sort((a, b) => b[0] - a[0]);
    return result[0]?.[1] || "(None)";
}
