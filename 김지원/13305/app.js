const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const d = input[1].split(' ').map((item) => BigInt(item));
const costs = input[2].split(' ').map((item) => BigInt(item));
costs.pop();
console.log(solution(d, costs));

function solution(d, costs) {
  let answer = 0;
  const minCost = Math.min(...costs);
  for (let i = 0; i < costs.length; i++) {
    if (costs[i] !== minCost) {
      answer += costs[i] * d[i];
    } else {
      for (let j = i; j < d.length; j++) {
        answer += minCost * d[j];
      }
      break;
    }
  }
  return answer;
}
