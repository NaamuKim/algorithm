// 우직하게 순서대로 품 문제는 배열의 크기가 너무 크다. (배열의 크기가 크면 에러가 난다.)
function solution(n, left, right) {
  var answer = [];
  let arr = Array.from(Array(n), () => Array(n).fill(0));
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      arr[i - 1][j - 1] = i;
      arr[j - 1][i - 1] = i;
    }
  }
  const newArr = [];
  arr.forEach((innerArr) => {
    newArr.push(...innerArr);
  });
  for (let i = left; i <= right; i++) {
    answer.push(newArr[i]);
  }
  return answer;
}
// 2차원 배열을 몫과 나머지를 이용하여 1차원 배열로 본다.
// 열과 행중에 큰거 + 1 이 answer배열에 들어갈 값이다.
function solution2(n, left, right) {
  var answer = [];
  // 0, 0 -> 1
  // 0, 1 -> 2 | 1, 0 -> 2 | 1, 1 -> 2
  // 0, 2 -> 3 | 1, 2 -> 3 | 2, 0 -> 3 | 2, 1 -> 3
  // 로우나 칼럼에 있는 숫자중에서 큰거에 +1한게 1차원배열에 들어감
  for (let i = left; i <= right; i++) {
    const col = Math.floor(i / n);
    const row = i % n;
    answer.push(Math.max(Math.floor(i / n), i % n) + 1);
  }
  return answer;
}
