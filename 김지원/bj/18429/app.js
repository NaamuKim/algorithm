const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let n=input[0].split(" ").shift();
let k=input[0].split(" ").pop();
let kit=input[1].split(" ").map((item)=>+item);

solution(n,k,kit);

function solution(n,k,kit) {
    let threeWeight=500;
    let cnt=0;
    let tmp=Array.from({length:n}, ()=>0);
    function DFS(L){
        if(L===n-1)   cnt++
        else{
            for(let i=0;i<n;i++){
                if(tmp[i]===0){
                    tmp[i]=1;
                    if(threeWeight+kit[i]>=500){
                        threeWeight+=kit[i];
                        DFS(L+1);
                        threeWeight-=kit[i];
                        tmp[i]=0;
                    }
                    else tmp[i]=0;
                }
            }
        }
    }
    for(let j=0;j<kit.length;j++){
        kit[j]-=k;
    }
    DFS(0);
    console.log(cnt);
}
