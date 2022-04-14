const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = [];
const sum = Number(input[0].split(' ')[1]);
for (let i = 1; i < input.length; i++) {
  arr.push(+input[i]);
}
console.log(solution(arr, sum));
function solution(coins, coinSum) {
  let answer = 0;
  for (let i = coins.length - 1; i >= 0; i--) {
    if (coinSum / coins[i] >= 1) {
      if (coinSum === 0) return;
      answer += parseInt(coinSum / coins[i]);
      coinSum -= parseInt(coinSum / coins[i]) * coins[i];
    }
  }
  return answer;
}
