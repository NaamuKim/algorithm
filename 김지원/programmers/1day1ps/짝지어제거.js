function solution(s) {
  let answer = -1;
  let stack = [];
  for (let i = 0; i < s.length; i++) {
    if (!stack.length || stack[stack.length - 1] !== s[i]) stack.push(s[i]);
    else stack.pop();
  }
  stack.length ? (answer = 0) : (answer = 1);
  return answer;
}
