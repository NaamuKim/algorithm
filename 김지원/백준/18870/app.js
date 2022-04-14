const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);


function solution(input) {
    let answer=[];
    let [n,nums]= input;
    nums=nums.split(" ").map((item)=>Number(item))
    const set=Array.from(new Set([...nums])).sort((a,b)=>a-b);
    const obj={};
    set.forEach((v,i)=>obj[v]=i);
    for(let i=0;i<nums.length;i++){
        answer.push(obj[nums[i]]);
    }
    console.log(answer.join(" "));
}

