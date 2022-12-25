const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
// const n = Number(input[0]);
input = input.map(Number);
console.log(solution());

function solution() {
  const dp = [];
  let result = '';
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (let i = 1; i < input.length; i++) {
    if (dp[input[i]]) {
      result += dp[input[i]] + '\n';
      continue;
    }
    for (let j = 4; j <= input[i]; j++) {
      if (dp[j]) continue;
      dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
    }
    result += dp[input[i]] + '\n';
  }
  return result;
}
