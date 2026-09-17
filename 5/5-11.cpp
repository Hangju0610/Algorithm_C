#include <bits/stdc++.h>
using namespace std;
int a[54][54], cnt[54][54], r, c, t, ret, maxY, minY;
int dy1[4] = {0, -1, 0, 1};
int dx1[4] = {1, 0, -1, 0};
int dy2[4] = {0, 1, 0, -1};
int dx2[4] = {1, 0, -1, 0};

vector<pair<int, int>> v1, v2;

vector<pair<int, int>> check(int sy, int sx, int dy[], int dx[]) {
    vector<pair<int, int>> v;
    int cnt = 0;
    int y = sy;
    int x = sx;
    while (true) {
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];
        if (ny == sy && nx == sx) break;
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if (ny == sy && nx == sx) break;
        y = ny;
        x = nx;
        v.push_back({ny, nx});
    }

    return v;
}

void dfs(int y, int x) {
    int diff = a[y][x] / 5;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy1[i];
        int nx = x + dx1[i];
        if (ny >= r || ny < 0 || nx >= c || nx < 0 || a[ny][nx] == -1) {
            continue;
        }
        cnt[ny][nx] += diff;
        cnt[y][x] -= diff;
    }
}

void go(vector<pair<int, int>>& v) {
    for (int i = v.size() - 1; i > 0; i--) {
        a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
    }
    a[v[0].first][v[0].second] = 0;
    return;
}

int main() {
    cin >> r >> c >> t;
    bool flag = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                if (flag) {
                    v1 = check(i, j, dy1, dx1);
                    flag = false;
                } else {
                    v2 = check(i, j, dy2, dx2);
                }
            }
        }
    }

    int current = 0;
    while (current < t) {
        current++;
        // 확산부터 진행
        fill(&cnt[0][0], &cnt[0][0] + (54 * 54), 0);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] > 0) dfs(i, j);
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] != -1) a[i][j] += cnt[i][j];
            }
        }

        go(v1);
        go(v2);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] > 0) ret += a[i][j];
        }
    }

    cout << ret;
}