const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

const Arr=input.map((v)=>Number(v));

console.log(solution(Arr));

function solution(arr) {
    let score=0;
    for(let i=0;i<arr.length;i++){
        score+=arr[i];
        if(score>100){
            let small=score-arr[i]
            if(100-small<score-100) return small;
            else return score;
        }
        else if(score===100) return 100;
    }
    return score;
}
