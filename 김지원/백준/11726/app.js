const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const n = +input.shift();
const arr = Array.from({ length: 1000 });
arr[1] = 1;
arr[2] = 2;
const solution = () => {
  for (let i = 3; i <= n; i++) {
    arr[i] = (arr[i - 2] + arr[i - 1]) % 10007;
  }
  console.log(arr[n]);
};

solution();
