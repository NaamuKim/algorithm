const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let arr=[];

for(let i=1;i<input.length;i++){
    arr.push(input[i]);
}


solution(arr);

function solution(arr) {
    arr.sort((a,b)=>a-b);
    for(let i=0;i<arr.length;i++){
        console.log(arr[i]);
    }
}
