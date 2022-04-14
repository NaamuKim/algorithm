const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let arr=[];
for(let i=1;i<input.length;i++){
    arr.push(input[i].split(" ").map(item=>+item));
}

solution(arr);

function solution(arr) {
    let rank=[];
    let n=arr.length;
    for(let i=0;i<n;i++){
        let cnt=1;
        for(let j=0;j<n;j++){
            if(i!==j&&arr[i][0]<arr[j][0]&&arr[i][1]<arr[j][1]) cnt++;
        }
        rank.push(cnt)
    }
    console.log(rank.join(" "));
}
