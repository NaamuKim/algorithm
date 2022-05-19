const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

let arr = [];
for (let i = 1; i < input.length; i++) {
  arr.push(input[i].split(',').map((item) => +item));
}
console.log(solution());

function solution() {
  let answer = '';
  arr.forEach((item) => {
    answer += item[0] + item[1];
    answer += '\n';
  });
  return answer;
}
