function solution(msg) {
  let answer = [];
  const alpha = [null, ...Array.from(Array(26)).map((e, i) => String.fromCharCode(i + 65))];
  let lp = 0,
    rp = msg.length - 1;
  while (1) {
    if (lp === msg.length - 1) break;
    console.log(rp - lp);
    const piece = msg.slice(lp, rp - lp + 1);
    console.log(piece);
    const idx = alpha.indexOf(piece);
    if (idx !== -1) {
      answer.push(idx);
      rp--;
      continue;
    }
    lp++;
  }
  return answer;
}
