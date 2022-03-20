const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = input[1].split(' ').map((item) => +item);

console.log(solution(arr));

function solution(P) {
  let answer = 0;
  P.sort((a, b) => a - b);
  let arrLeng = P.length;
  for (let x of P) {
    answer += arrLeng * x;
    arrLeng--;
  }
  return answer;
}
