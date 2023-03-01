const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

let n = +input.shift();

const dp = Array.from({ length: 91 }).fill(0);

const fibo = (idx) => {
  if (idx === 0 || idx === 1) return idx;
  if (dp[idx]) return BigInt(dp[idx]);
  return (dp[idx] = BigInt(fibo(idx - 1)) + BigInt(fibo(idx - 2)));
};

const solution = () => {
  return fibo(n);
};

console.log(solution().toString());
