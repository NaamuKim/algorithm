const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let n=input[0].split(" ").shift();
let m=input[0].split(" ").pop();

solution(+n,+m);

function solution(n,m) {
    let tmp=Array.from({length:m}, ()=>0);
    function DFS(L,s){
        if(L===m){
            console.log(tmp.slice().join(" "));
        }
        else {
            for (let i = s; i <= n; i++) {
                tmp[L]=i;
                DFS(L+1,i+1);
            }
        }
    }

    DFS(0,1);
}