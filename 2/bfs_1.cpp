#include <bits/stdc++.h>
using namespace std;

int n, m, a[104][104], sy, sx, ey, ex, ret;
int visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()) {
        auto here = q.front();
        q.pop();
        cout << here.first << " : " << here.second << '\n';
        for (int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if (ny < 0 || ny > n || nx < 0 || nx > m) continue;
            if (a[ny][nx] == 0) continue;
            if (visited[ny][nx])
                continue;
            visited[ny][nx] = visited[here.first][here.second] + 1;

            // 목적지 도달하면 종료!
            if (ny == ey && nx == ex) {
                cout << "목적지 도착 " << ny << " : " << nx << '\n';
                ret = visited[ny][nx];
                break;
            }
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;

    for (int i = 0; i < n; i++ ) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bfs(sy, sx);
    cout << ret << '\n';
    return 0;
}


/*
BFS는 그래프를 탐색하는 알고리즘이며, 어떤 정점에서 시작해 다음 깊이의 정점으로 이동하기 전
현재 깊이의 모든 정점을 탐색하며 방문한 정점은 다시 방문하지 않는 알고리즘입니다.
같은 가중치를 가진! 그래프에서 최단거리 알고리즘으로 쓰입니다.

BFS를 구현 방법은 Queue를 써서 구현합니다.
*/