/*
1. 육지 내 최단거리가 가장 긴 곳의 두 포인트 (단, 멀리 돌아가거나, 방문한 지역 재방문 제외)
-> 최단거리이면서, 먼 경우를 어떻게 계산하는가?
bfs를 돌려서 해결한다.
-> 
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, visited[51][51], mx;
char a[51][51];
string s;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (a[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'L')
                bfs(i, j);
        }
    }

    cout << mx - 1 << '\n';
    return 0;
}