const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const [a, b, c] = input[0].split(' ').map((item) => +item);
let cnt = [];
console.log(solution());
function solution() {
  let answer = 0;
  for (let i = 1; i <= 3; i++) {
    const [s, e] = input[i].split(' ').map((item) => +item);
    for (let j = s; j < e; j++) {
      cnt[j] ? cnt[j]++ : (cnt[j] = 1);
    }
  }
  for (let item of cnt) {
    if (item === 1) answer += a;
    else if (item == 2) answer += b * 2;
    else if (item == 3) answer += c * 3;
  }
  return answer;
}
