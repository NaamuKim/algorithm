const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

console.log(solution());

function solution() {
  const [hour, min] = input[0].split(' ').map((item) => +item);
  const delay = Number(input[1]);
  const wholeTimeToMinute = hour * 60 + min + delay;

  const endHour = parseInt(wholeTimeToMinute / 60);
  const endMin = parseInt(wholeTimeToMinute % 60);

  if (endHour >= 24) {
    return endHour - 24 + ' ' + endMin;
  } else {
    return endHour + ' ' + endMin;
  }
}
