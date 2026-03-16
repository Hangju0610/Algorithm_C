#include <bits/stdc++.h>
using namespace std;

/*
미로 내 최단 거리 -> BFS 구현
1. 배열로 표현된 지도 -> array로 구현 진행
2. BFS 구현 -> Queue로 구현하기
3. (1, 1) -> (N, M)으로 이동하는 최단거리 구하기
*/

int n, m, a[104][104], v[104][104], ret;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    v[y][x] = 1;
    q.push({y, x});
    while(q.size()) {
        auto h = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = h.first + dy[i];
            int nx = h.second + dx[i];
            if (ny < 0 || ny > n || nx < 0 || nx > m)
                continue;
            if (a[ny][nx] == 0)
                continue;
            if (v[ny][nx])
                continue;
            v[ny][nx] = v[h.first][h.second] + 1;

            if (ny == n - 1 && nx == m - 1) {
                ret = v[ny][nx];
                break;
            }
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    bfs(0, 0);
    cout << ret << '\n';
}