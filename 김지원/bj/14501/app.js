const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

const n=Number(input[0]);
const Arr=input.slice(1).map((v)=>v.split(' ').map((v)=>Number(v)));
solution(n, Arr);

function solution(n, Arr) {
    const dp= new Array(n).fill(0)
    for (let i = 0; i < n; i++) {
        const [cost, profit] = Arr[i];
        if (i + cost > n) continue;
        dp[i] = dp[i] + profit;
        for (let j = i + cost; j < n; j++) {
            dp[j] = Math.max(dp[j], dp[i]);
        }
    }
    console.log(Math.max(...dp));
}
