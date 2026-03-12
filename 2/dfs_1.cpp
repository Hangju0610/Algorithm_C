#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int a[104][104], visited[104][104], ret, n, m;

// 1. map을 받는다.
// 2. 목표 : connected component 개수 측정
// 3. 

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx > m) continue;
        if (a[ny][nx] == 0) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0 && visited[i][j] == 0) {
                dfs(i, j);
                ret++;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}