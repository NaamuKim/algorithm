const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const str = input[0];

console.log(solution());

function solution() {
  let answer = '';
  let rev = '';
  for (let i = 0; i < str.length; i++) {
    if (str[i] === '<') {
      answer += rev.split('').reverse().join('');
      rev = '';
      while (str[i] != '>') {
        answer += str[i];
        i++;
      }
      answer += '>';
    } else if (str[i] === ' ') {
      answer += rev.split('').reverse().join('');
      answer += ' ';
      rev = '';
    } else {
      rev += str[i];
    }
  }
  answer += rev.split('').reverse().join('');
  return answer;
}
