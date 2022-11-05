// 재귀 시간초과
function solution(n) {
  let answer = 0;
  const arr = [1, 2];

  function dfs(sum) {
    if (sum === n) {
      answer++;
      return;
    }
    for (let i = 0; i < 2; i++) {
      if (sum + arr[i] > n) return;
      dfs(sum + arr[i]);
    }
  }
  dfs(0);
  return answer;
}

// 피보나치 풀이 통과
function solution(n) {
  // 사실상 4->5, 3->3 을보고 피보나치로 각을 재고 풀어야했음
  // 모듈러가 숨겨져 있다. (1234567)로 나누라는 것도 힌트였을듯
  // 생각한 논리
  // 재귀 겁나클텐데? 그럼 배열을 만들어서 순회하면 O(n)아니야?
  // 근데 무슨 배열?
  // 잘 생각해보면 그 전에꺼까지 오거나 그 전전까지 오는 거 더하면 되는 거 아니야?
  if (n < 2) return 1;
  const cnt = [0, 1, 2, ...Array.from({ length: n - 2 }).fill(0)];
  cnt.forEach((it, i) => {
    if (i > 2) cnt[i] = (cnt[i - 2] + cnt[i - 1]) % 1234567;
  });
  return cnt[n];
}
