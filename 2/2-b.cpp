#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, a[54][54], v[54][54], ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    v[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny > n || nx < 0 || nx > m)
            continue;
        if (a[ny][nx] == 0 || v[ny][nx] == 1)
            continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> t;
    for (int c = 0; c < t; c++) {
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++) {
            int y, x;
            cin >> x >> y;
            a[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0 && v[i][j] == 0) {
                    ret++;
                    dfs(i, j);
                }
            }
        }

        cout << ret << '\n';

        // a와 v를 초기화 진행
        memset(a, 0, sizeof(a));
        memset(v, 0, sizeof(v));
        ret = 0;
    }

    return 0;
}

/*
1. 유기농 배추 배열 위치 확인,
Test case가 있으니 초기화가 필요하다.

2. 배추 입력 진행 후 DFS로 Connected case 확인

*/