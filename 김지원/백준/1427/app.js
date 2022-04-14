const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(arr) {
    let answer=arr.toString().split("").map((item)=>+item).sort((a,b)=>b-a).join("");
    console.log(answer);
}
