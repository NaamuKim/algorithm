const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const [N, M] = input.shift().split(' ');

const Nset = new Set();
const Mset = new Set();
for (let i = 0; i < input.length; i++) {
  if (i < N) {
    Nset.add(input[i]);
  } else {
    Mset.add(input[i]);
  }
}

let answer = [];
Mset.forEach((item) => {
  if (Nset.has(item)) answer.push(item);
});
answer.sort();

console.log(solution());

function solution() {
  return answer.length + '\n' + answer.join('\n');
}
