function timeConversion(s) {
    const time = s.slice(0, - 2);
    const [hh, mm, ss] = time.split(':');
    
    const isAM = s.slice(-2) === "AM";
    if(isAM){
        if(hh === '12') return `00:${mm}:${ss}`;
        return time;
    } else{
        if(hh === '12') return time;
        return `${parseInt(hh) + 12}:${mm}:${ss}`;
    }
}
