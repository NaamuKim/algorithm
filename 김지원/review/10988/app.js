const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

console.log(solution());

function solution() {
  let s = input[0];
  if (s.split('').reverse().join('') == s) return 1;
  else return 0;
}
