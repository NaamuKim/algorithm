function solution(n) {
  let ans = 0;
  //일단 하나는 가야함
  //해당 수 미만의 제일 가까운 2배수 이동을 반복
  // 남은 만큼 더함
  while (n > 0) {
    if (n % 2) {
      n -= 1;
      ans++;
      continue;
    }
    n /= 2;
  }
  return ans;
}
