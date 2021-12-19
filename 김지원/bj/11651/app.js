const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let Arr=[];
for(let i=1;i<input.length;i++){
    Arr.push(input[i].toString().split(" ").map((item)=>Number(item)));
}

solution(input[0], Arr);


function solution(n, arr) {
    let answer=""
    arr.sort((a,b)=>{
        if(a[1]===b[1]) return(a[0]-b[0])
        else return a[1]-b[1]
    }).forEach(item=>{
        answer+=`${item[0]} ${item[1]}\n`;
    })
    console.log(answer);
}

