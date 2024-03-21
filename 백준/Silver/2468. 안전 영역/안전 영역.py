from sys import stdin
from collections import deque


def dfs(area, rain):
    res = 0
    visited = [[0 for i in range(N)] for _ in range(N)]
    for r in range(N):
        for c in range(N):
            if not visited[r][c] and area[r][c] > rain:
                q = deque([(r, c)])
                visited[r][c] = True

                while q:
                    x, y = q.popleft()
                    for dx, dy in (0, -1), (0, 1), (-1, 0), (1, 0):
                        nx, ny = dx + x, dy + y

                        if 0 <= nx < N and 0 <= ny < N:
                            if area[nx][ny] > rain and not visited[nx][ny]:
                                visited[nx][ny] = True
                                q.append((nx, ny))
                res += 1
    return res


N = int(stdin.readline().strip())
area = [list(map(int, stdin.readline().split())) for _ in range(N)]
max_height, min_height = max(max(area)), min(min(area))

max_land = 1

for rain in range(0, 101):
    land = dfs(area, rain)
    if max_land < land:
        max_land = land
print(max_land)