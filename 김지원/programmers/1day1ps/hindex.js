function solution(citations) {
  let answer = 0;
  let max = Math.max(...citations);
  console.log(max);
  for (let i = 0; i <= max; i++) {
    let cnt = 0;
    for (let x of citations) {
      if (x >= i) cnt++;
    }
    if (cnt >= i) {
      answer = Math.max(answer, i);
    }
  }
  return answer;
}
