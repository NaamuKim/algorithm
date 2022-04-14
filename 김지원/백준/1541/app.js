const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = input[0];

console.log(solution(arr));

function solution(ex) {
  let answer = 0;
  ex = ex.split('-').map((str) =>
    str
      .split('+')
      .map((item) => +item)
      .reduce((s, v) => s + v, 0)
  );
  answer = ex[0] * 2 - ex.reduce((s, v) => s + v, 0);
  return answer;
}
