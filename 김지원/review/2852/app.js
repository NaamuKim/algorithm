const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const n = +input[0];
let a = 0;
let b = 0;
let asum = 0;
let bsum = 0;
let prev = '';
console.log(solution());

function print(n) {
  let d = '00' + String(n / 60);
  let e = '00' + String(n % 60);
  return d.substring(d.length - 2) + ':' + e.substring(e.length - 2);
}

function sToTime(s) {
  let time = s.split(':').map((item) => +item);
  return time[0] + time[1] * 60;
}

function go(sum, s) {
  console.log(s, prev);
  sum += sToTime(s) - sToTime(prev);
}

function solution() {
  let answer = '';
  for (let i = 1; i < n + 1; i++) {
    let [team, time] = input[i].split(' ');
    if (a > b) go(asum, time);
    if (b > a) go(bsum, time);
    team === '1' ? a++ : b++;
    prev = time;
  }
  if (a > b) go(asum, '48:00');
  if (b > a) go(bsum, '48:00');
  answer = print(asum) + '\n' + print(bsum);
  return answer;
}
