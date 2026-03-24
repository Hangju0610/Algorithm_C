/*
1. 벽을 세운다. 0인 곳에 1을 넣는다.
2. dfs를 한다. 0의 개수를 측정한다.
3. 다시 원복한다.
*/

#include <bits/stdc++.h>
using namespace std;

int wall = 3;
int n, m, a[8][8], cnt, v[8][8];
vector<pair<int, int>> emptySpace;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= n || ny < 0 || nx >= m || nx < 0)
            continue;
        if (v[ny][nx] == 1 || v[ny][nx] == 2)
            continue;
        v[ny][nx] = 2;
        dfs(ny, nx);
    }
}

void combi(int start, vector<pair<int, int>> &b) {
    if (b.size() == 3) {
        // 벽 생성
        for (auto i : b) {
            a[i.first][i.second] = 1;
        }

        memcpy(v, a, sizeof(a));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 2) {
                    dfs(i, j);
                }
            }
        }

        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 0)
                {
                    temp++;
                }
            }
        }
        if (temp > cnt) {
            cnt = temp;
        }

        // 벽 다시 원복
        for (auto i : b)
        {
            a[i.first][i.second] = 0;
        }
        return;
    }

    for (int i = start + 1; i < emptySpace.size(); i++) {
        b.push_back(emptySpace[i]);
        combi(i, b);
        b.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                emptySpace.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> a;
    combi(-1, a);

    cout << cnt;
    return 0;
}
