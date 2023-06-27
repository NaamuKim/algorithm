function solution(msg) {
  let answer = [];
  const alpha = [
    null,
    ...Array.from(Array(26)).map((e, i) => String.fromCharCode(i + 65)),
  ];
  let lp = 0;
  while (lp < msg.length) {
    let word = "";
    while (alpha.includes(word + msg[lp])) {
      word += msg[lp++];
    }
    answer.push(alpha.indexOf(word));
    alpha.push(word + msg[lp]);
  }

  return answer;
}
