const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const one = +input[0];
const arr = input[1].split(' ').map((item) => Number(item));

console.log(solution());

function solution() {
  let answer = 0;
  arr.forEach((item) => {
    if (item === one) answer++;
  });
  return answer;
}
