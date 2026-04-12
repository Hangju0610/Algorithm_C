/*
꽃의 씨앗은 3개 뿐
6≤N≤10
0≤G≤200

최소 비용이 되도록 꽃을 심는 임무
*/

#include <bits/stdc++.h>
using namespace std;

int a[11][11], visited[11][11], ret = 987654321, n;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void eraseFlower(int y, int x) {
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

int seedFlower(int y, int x) {
    visited[y][x] = 1;
    int s = a[y][x];
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        s += a[ny][nx];
    }

    return s;
}

bool check(int y, int x) {
    if (visited[y][x]) return 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
            return 0;
        }
    }

    return 1;
}

void go(int cnt, int priceSum) {
    if (cnt == 3) {
        ret = min(ret, priceSum);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                go(cnt + 1, priceSum + seedFlower(i, j));
                eraseFlower(i, j);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 0);
    cout << ret;
    return 0;
}