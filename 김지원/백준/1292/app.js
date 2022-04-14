const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const [start, end] = input[0].split(' ').map((item) => +item);

console.log(solution([start, end]));

function solution([start, end]) {
  let answer = 0;
  let arr = [0];
  let cnt = 0;
  let num = 1;
  while (arr.length <= end) {
    arr.push(num);
    cnt++;
    if (cnt === num) {
      num++;
      cnt = 0;
    }
  }
  answer = arr.slice(start, end + 1).reduce((sum, cur) => sum + cur, 0);
  return answer;
}
