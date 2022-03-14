const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

console.log(solution());

function solution() {
  const arr = input[0].split(' ').map((item) => +item);
  if (arr[0] === arr[1] && arr[0] === arr[2] && arr[1] === arr[2]) {
    return 10000 + arr[0] * 1000;
  } else if (arr[0] === arr[1] || arr[1] === arr[2] || arr[0] === arr[2]) {
    if (arr[0] === arr[1] || arr[0] === arr[2]) return 1000 + arr[0] * 100;
    else return 1000 + arr[1] * 100;
  } else {
    return Math.max(arr[0], arr[1], arr[2]) * 100;
  }
}
