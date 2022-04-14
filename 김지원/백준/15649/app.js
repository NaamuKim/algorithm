const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let n=input[0].split(" ").shift();
let m=input[0].split(" ").pop();

solution(+n,+m);

function solution(n,m) {
    let ch=Array.from({length:n}, ()=>0);
    let tmp=Array.from({length:m}, ()=>0);
    function DFS(L){
        if(L===m){
            console.log(tmp.slice().join(" "));
        }
        else {
            for (let i = 0; i < n; i++) {
                if(ch[i]===0){
                    ch[i] = 1;
                    tmp[L] = i+1;
                    DFS(L + 1);
                    ch[i] = 0;
                }
            }
        }
    }
    DFS(0);
}
