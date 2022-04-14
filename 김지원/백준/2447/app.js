const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = [];
console.log(solution(+input[0]));

function solution(n) {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      starPushing(i, j, n);
    }
    arr.push('\n');
  }
  return arr.join('');
}

function starPushing(i, j, num) {
  if (i % 3 === 1 && j % 3 === 1) {
    arr.push(' ');
  } else {
    if (num === 1) {
      console.log(i, j, num);
      arr.push('*');
    } else {
      starPushing(parseInt(i / 3), parseInt(j / 3), parseInt(num / 3));
    }
  }
}
