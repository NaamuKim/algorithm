const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');
let arr=[];
for(let i=1;i<input.length;i++){
    arr.push(Number(input[i].trim()))
}
console.log(arr);
solution(arr);

function solution(arr) {
    arr.sort((a,b)=>a-b);
    let sum=arr.reduce((a,b)=>a+b,0);
    let sH=new Map();
    for(let x of arr){
        if(sH.has(x)) sH.set(x,sH.get(x)+1);
        else sH.set(x,1);
    }
    let max=1;
    let maxKey=1;
    for(let [key,val] of sH){
        if(max<val) maxKey=key;
    }
    console.log(Math.round(sum/arr.length));
    console.log(arr[parseInt(arr.length/2)]);
    console.log(maxKey);
    console.log(arr[arr.length-1]-arr[0]);
}
