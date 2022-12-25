const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
input = input.map(Number);
console.log(solution());

function solution() {
  const dp = Array.from(Array(41), () => Array(2).fill(null));
  let result = '';
  dp[0] = [1, 0];
  dp[1] = [0, 1];
  for (let i = 1; i < input.length; i++) {
    const item = dp[input[i]];
    if (input[i] === 0 || input[i] === 1) {
      result += item[0] + ' ' + item[1] + '\n';
      continue;
    }
    for (let j = 2; j <= input[i]; j++) {
      if (dp[j][0] > 0 || dp[j][1] > 0) continue;
      dp[j][0] = dp[j - 1][0] + dp[j - 2][0];
      dp[j][1] = dp[j - 1][1] + dp[j - 2][1];
    }
    result += item[0] + ' ' + item[1] + '\n';
  }
  return result;
}
