process.stdin.setEncoding('utf8');
process.stdin.on('data', data => {
    let [a, b] = data.split(" ");
    
    console.log(`${"*".repeat(a)}\n`.repeat(b)); 
});
