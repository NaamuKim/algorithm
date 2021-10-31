const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let arr=[];
solution(+input[0]);

function splitSum(n){
    let num=n.toString().split("").map(item=>+item).reduce((a,b)=>a+b);
    return num+n;
}

function solution(n) {
    for(let i=0;i<=n;i++){
        if(splitSum(i)===n) arr.push(i);
    }
    arr.sort((a,b)=>a-b);
    if(arr[0])console.log(arr[0]);
    else console.log(0);
}
