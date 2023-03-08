const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

const dp = Array.from({ length: 31 }, () => Array.from({ length: 31 }).fill(0));

const go = (whole, half) => {
  if (!whole && !half) return 1;
  if (dp[whole][half]) return dp[whole][half];
  if (whole) dp[whole][half] += go(whole - 1, half + 1);
  if (half) dp[whole][half] += go(whole, half - 1);
  return dp[whole][half];
};

const solution = () => {
  input.forEach((day) => day && console.log(go(day, 0)));
};

solution();
