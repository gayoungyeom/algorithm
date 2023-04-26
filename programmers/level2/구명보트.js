function solution(people, limit) {
    people.sort((a, b) => a - b);
    
    let boat = 0;
    let front = 0;
    let back = people.length - 1;
    
    while(front < back){
        const weight = people[front] + people[back];
        if(weight <= limit){
            front++;
        } 
        back--;
        boat++;
    }
    if(front === back) boat++;

    return boat;
}
