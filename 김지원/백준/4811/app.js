const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

const dp = Array.from({ length: 31 }, () => Array.from({ length: 31 }).fill(0));

const go = (whole, notWhole) => {
  if (!whole && !notWhole) return 1;
  if (dp[whole][notWhole]) return dp[whole][notWhole];
  if (whole) dp[whole][notWhole] += go(whole - 1, notWhole + 1);
  if (notWhole) dp[whole][notWhole] += go(whole, notWhole - 1);
  return dp[whole][notWhole];
};

const solution = () => {
  input.forEach((day) => day && console.log(go(day, 0)));
};

solution();
