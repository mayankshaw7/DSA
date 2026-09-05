/**
 * @param {string} s
 * @return {number}
 */
var secondHighest = function(s) {
    let first=-1;
    let second=-1;

    for(let i=0;i<s.length;i++){
        if(s[i]>='0' && s[i]<='9'){
            let num=s[i]-'0';
            if(num>first){
                second=first;
                first=num;
            }else if(num!=first && num>second){
                second=num;
            }
        }
    }
        return second;
    
};