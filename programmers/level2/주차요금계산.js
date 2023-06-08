const parkingTime = (inTime, outTime) => {
    const [inH, inM] = inTime.split(":").map(Number);
    const [outH, outM] = outTime.split(":").map(Number);
    return (outH * 60 + outM) - (inH * 60 + inM);
}

const parkingFee = (fees, minutes) => {
    const [defaultTime, defaultFee, unitTime, unitFee] = fees;
    if(minutes <= defaultTime) return defaultFee;
    return defaultFee + Math.ceil((minutes - defaultTime) / unitTime) * unitFee;
}

function solution(fees, records) {
    const result = []; //[차량 번호, 주차 요금]
    const inCars = {}; //[차량 번호]: 입차 시각
    const accTimes = {}; //[차량 번호]: 누적 주차 시간
    
    //누적 주차 시간 계산
    for(const record of records){
        const [time, car, type] = record.split(" ");
        if(type === "IN"){
            inCars[car] = time;
        } else{ //OUT
            const minutes = parkingTime(inCars[car], time);
            if(accTimes[car]) accTimes[car] += minutes;
            else accTimes[car] = minutes;
            delete inCars[car];
        }
    }
    
    //출차 내역이 없는 경우
    for(const inCar of Object.entries(inCars)){
        const minutes = parkingTime(inCar[1], "23:59");
        if(accTimes[inCar[0]]) accTimes[inCar[0]] += minutes;
        else accTimes[inCar[0]] = minutes;
    }
    
    //주차 요금 계산
    for(const accTime of Object.entries(accTimes)){
        result.push([accTime[0], parkingFee(fees, accTime[1])]);
    }
    
    return result.sort((a, b) => a[0] - b[0]).map(v => v[1]);;
}
