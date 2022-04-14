const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const [a, b] = input[0].split(' ').map((item) => Number(item));

console.log(solution());

function solution() {
  let answer = 0;
  answer = a - b;
  return answer;
}
