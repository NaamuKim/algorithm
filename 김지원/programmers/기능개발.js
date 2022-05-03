function solution(progresses, speeds) {
  let answer = [];
  let days = 1;
  let cnt = 0;
  while (progresses[0]) {
    let progress = progresses[0] + speeds[0] * days;
    if (progress >= 100) {
      progresses.shift();
      speeds.shift();
      cnt++;
    } else {
      if (cnt > 0) answer.push(cnt);
      days++;
      cnt = 0;
    }
  }
  answer.push(cnt);

  return answer;
}
