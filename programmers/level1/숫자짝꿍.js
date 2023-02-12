function solution(X, Y) {
    const mapX = new Map();
    const mapY = new Map();
    [...X].forEach(v => mapX.set(v, mapX.has(v) ? mapX.get(v) + 1 : 1));
    [...Y].forEach(v => mapY.set(v, mapY.has(v) ? mapY.get(v) + 1 : 1));
    
    let str = "";
    mapX.forEach((v, k) => mapY.has(k) ? str += k.repeat(Math.min(mapY.get(k), v)) : null);
    return str ? [...str].some(s => s !== '0') ? [...str].sort((a, b) => b - a).join('') : "0" : "-1";
}
