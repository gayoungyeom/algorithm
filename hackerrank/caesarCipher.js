const TOTAL_ALPHA_COUNT = 26;
const LOWER_LAST_CODE = 122;
const UPPER_LAST_CODE = 90;

function caesarCipher(s, k) {
    let result = '';
    
    for(let i = 0; i < s.length; i++){
        const code = s[i].charCodeAt();
        let encrypt = code + (k % TOTAL_ALPHA_COUNT);

        if(s[i].match(/^[a-z]/)){
            if(encrypt > LOWER_LAST_CODE) encrypt -= TOTAL_ALPHA_COUNT;
            result += String.fromCharCode(encrypt);
        } else if(s[i].match(/^[A-Z]/)){
            if(encrypt > UPPER_LAST_CODE) encrypt -= TOTAL_ALPHA_COUNT;
            result += String.fromCharCode(encrypt);            
        }else{
            result += s[i];
        }
    }
    
    return result;
}
