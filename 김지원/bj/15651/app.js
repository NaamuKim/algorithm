const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');


console.log(solution(input[0].split(" ").map((i)=>Number(i))).join(""));


function solution(arr) {
    let answer=[]
    let n=arr[0];
    let m=arr[1];
    let tmp=Array.from({length:m}, ()=>0);
    function DFS(L){
        if(L===m) answer.push(tmp.slice().join(" ")+"\n")
        else{
            for(let i=1;i<=n;i++){
                tmp[L]=i;
                DFS(L+1);
            }
        }
    }
    DFS(0);
    return answer;
}

