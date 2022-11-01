const discounts = [[100000, 0.95], [300000, 0.9], [500000, 0.8]];

function solution(price) {
    let pay = price;
    discounts.forEach(discount => {
        if(price >= discount[0]) pay = price * discount[1];
    })
    return ~~(pay);
}
