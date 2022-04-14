const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');


console.log(solution(input[0].split(" ").map((i)=>Number(i))).join(""));

// 큰 for문을 돌아올 때마다
// 두번째 자리에 첫번째 자리에 기준이 됐던 숫자가 안들어가게
function solution(arr) {
    let answer=[]
    let n=arr[0];
    let m=arr[1];
    const tmp=[];
    function DFS(L,s){
        if(L===m) answer.push(tmp.join(" ")+"\n")
        else{
            for(let i=s;i<n;i++){
                        tmp.push(i+1);
                        DFS(L+1,i);
                        tmp.pop()
                }
            }
        }

    DFS(0,0);
    return answer;
}

