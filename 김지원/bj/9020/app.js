const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');


const isPrime=(n)=>{
    if(n===2) return true;
    for(let i=2;i<=Math.sqrt(n);i++ ){
        if(n%i===0) return false;
    }
    return true;
}

const gold = (n) => {
    let Arr=[];
    for(let i=2;i<=n/2;i++){
        if(isPrime(i)&&isPrime(n-i)){
            Arr.push([i, n-i]);
        }
    }
    Arr.sort((a,b)=>{
        return Math.abs(a[0]-a[1])-Math.abs(b[0]-b[1]);
    })
    return Arr[0];
}

solution(input);


function solution(arr) {
    for(let i=1;i<arr.length;i++){
        console.log(gold(arr[i]).join(" "));
    }
}


