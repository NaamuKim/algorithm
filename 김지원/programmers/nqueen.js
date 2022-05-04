function solution(n) {
  let col = Array.from({ length: n }, () => -1);
  const check = (here) => {
    for (let i = 0; i < here; i++) {
      if (col[i] === col[here]) return false;
      if (Math.abs(col[here] - col[i]) === here - i) return false;
    }
    return true;
  };
  const solve = (here) => {
    if (here === n) return 1;
    let ret = 0;
    for (let row = 0; row < n; row++) {
      col[here] = row;
      if (check(here)) ret += solve(here + 1);
      col[here] = -1;
    }
    return ret;
  };
  return solve(0);
}
