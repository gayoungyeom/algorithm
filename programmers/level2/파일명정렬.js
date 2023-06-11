//file.match(/(\D+)(\d+)/) -> ex) img12.png => [[img12], [img], [12], index: 0, input: img12.png]
function solution(files) {    
    const newFiles = files.map((file) => file.match(/(\D+)(\d+)/));
    
    newFiles.sort((a, b) => {
        const [aFileName, aHead, aNum] = a;
        const [bFileName, bHead, bNum] = b;
     
        if(aHead.toUpperCase() > bHead.toUpperCase()){
            return 1;
        } else if(aHead.toUpperCase() < bHead.toUpperCase()){
            return -1;
        } else{
            return aNum - bNum;
        }    
    });
    
    return newFiles.map(file => file.input);
}
