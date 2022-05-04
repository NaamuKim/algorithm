function gcd(a, b) {
  const r = a % b;
  if (r === 0) return b;
  return gcd(r, b);
}
function solution(n, m) {
  let answer = [];
  answer.push(gcd(n, m));
  answer.push((n * m) / answer[0]);
  return answer;
}
