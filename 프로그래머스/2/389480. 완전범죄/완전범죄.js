function solution(info, n, m) {
  const len = info.length;
  let answer = Infinity;

  // visited[i][a][b] = 이 상태를 이미 본 적 있음
  const visited = Array.from({ length: len + 1 }, () =>
    Array.from({ length: n }, () =>
      Array(m).fill(false)
    )
  );

  function dfs(i, aSum, bSum) {
    // 경찰에 걸리면 실패
    if (aSum >= n || bSum >= m) return;

    // 모든 물건을 다 처리했을 때
    if (i === len) {
      answer = Math.min(answer, aSum);
      return;
    }

    if (visited[i][aSum][bSum]) return;
    visited[i][aSum][bSum] = true;

    const [a, b] = info[i];

    // i번째 물건을 A가 훔치는 경우
    dfs(i + 1, aSum + a, bSum);

    // i번째 물건을 B가 훔치는 경우
    dfs(i + 1, aSum, bSum + b);
  }

  dfs(0, 0, 0);

  return answer === Infinity ? -1 : answer;
}