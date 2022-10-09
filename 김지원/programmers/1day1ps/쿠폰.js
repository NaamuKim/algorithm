// 1번 쿠폰
// Map 자료 구조 사용
// 배열과 map중에 고른 이유는 key가 명시적인 게 더 좋다고 생각해서
// 그리고 map이 삽입은 일반 객체리터럴보다 느릴 수 있지만 조회가 더 빠른 것을 알고있다.

// 2번 호수
// 생각한 방향은 영역 세개를 어떻게 다룰 것이냐였음
// 호수와 육지 바다가 있음
// 바다와 호수를 어떻게 분리해볼까를 생각했는데
// 바다가 모서리 영역에 있으므로 모서리 영역부터 dfs방식의 탐색을 돌려서 육지가 나오기 전까지 부분이 바다겠구나라고 생각했음
// 그래서 바다 2 육지 1 호수 0인 상태로 분리를 해놓고
// 호수시작점에서 dfs함수가 시작되어 주변에 방문했던 지점이 나오거나 육지가 나올때까지 카운팅했음
function dfs(y, x) {
  let cnt = 1;
  if (vis[y][x]) return;
  vis[y][x] = 1;
  for (let i = 0; i < 4; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny > rows - 1 || nx > columns - 1) continue;
    if (arr[ny][nx] == 0 && !vis[ny][nx]) cnt += dfs(ny, nx);
  }
  return cnt;
}
for (let i = 0; i < rows; i++) {
  for (let j = 0; j < columns; j++) {
    if (!vis[i][j] && arr[i][j] == 1) {
      answer.push(dfs(i, j));
    }
  }
}
