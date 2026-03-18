#include <bits/stdc++.h>
using namespace std;

// 2차원 배열 최대 100, 각 원소 최소 1 ~ 100;
int n, a[104][104], m, ret, c, v[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int h) {
    v[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny > n || ny < 0 || nx > n || nx < 0)
            continue;
        if (v[ny][nx])
            continue;
        if (a[ny][nx] <= h)
            continue;
        dfs(ny, nx, h);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] > m)
                m = a[i][j];
        }
    }

    for (int i = 0; i <= m; i++) {
        fill(&v[0][0], &v[0][0] + 101 * 101, 0);
        c = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[j][k] > i && v[j][k] == 0) {
                    c++;
                    dfs(j, k, i);
                }
            }
        }
        ret = max(ret, c);
    }
    cout << ret << '\n';
}

/*
아무것도 잠기지 않는 케이스가 있을 수 있다. => 비가 오지 않는 경우의 수도 생각하자.
*/