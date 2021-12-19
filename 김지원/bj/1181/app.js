const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let Arr=[];
for(let i=1;i<input.length;i++){
    Arr.push(input[i].toString().trim());
}

solution(input[0], Arr);


function solution(n, arr) {
    let answer=""
    arr.sort().sort((a,b)=>a.length-b.length).filter((e,i)=>{
        return arr.indexOf(e)===i
    }).forEach(item=>{
        answer+=`${item}\n`;
    })
    console.log(answer);
}

