const isPrime = (n) => {
  if (n <= 1) return false;
  for (let i = 2; i <= Math.sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
};
function solution(n, k) {
  let answer = -1;
  if (n === 1) return 1;
  const arr = n
    .toString(k)
    .split('0')
    .filter((item) => item);
  answer = arr.filter((item, idx) => isPrime(item)).length;
  return answer;
}

console.log(solution(437674, 3));
