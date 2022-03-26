const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = [];
for (let i = 1; i < input.length; i++) {
  arr.push(input[i].split('').map((item) => +item));
}
const [xlength, ylength] = input[0].split(' ').map((item) => +item);
const check = Array.from({ length: xlength }, () => Array(ylength).fill(0));
console.log(solution(arr));

function solution(board) {
  let answer = 0;
  function DFS(x, y) {
    const dx = [-1, 0, 1, 0];
    const dy = [0, 1, 0, -1];
  }
  DFS(0, 0);
  return;
}
