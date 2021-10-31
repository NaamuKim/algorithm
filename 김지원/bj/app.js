const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let arr=[];
for(let i=1;i<input.length;i++){
    arr.push(input[i].trim().split(""))
}
solution(arr);

function solution(arr) {
    let answer=0;
    for(let i=0;i<arr.length;i++){
        for(let j=0;j<arr[1].length;i++){
            let start=arr[i][j]
            let cnt=0;
            for(let k=i; k<i+8;k++){

                for(let s=j;s<j+8;s++){
                    if(arr[k][s]===arr[k][s+1]) cnt++;
                }
                answer=Math.max(answer,cnt);
            }
        }
    }
    console.log(answer);
}
