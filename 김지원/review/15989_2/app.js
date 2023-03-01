const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

let t = +input.shift();

const solution = () => {
  const dp = Array.from({ length: 10001 }).fill(0);
  dp[0] = 1;
  for (let i = 1; i <= 3; i++) {
    for (let j = 1; j <= 10001; j++) {
      if (j >= i) dp[j] += dp[j - i];
    }
  }
  let i = 0;
  let ret = '';
  while (t--) {
    ret += dp[input[i]] + '\n';
    i++;
  }
  return ret;
};

console.log(solution());
