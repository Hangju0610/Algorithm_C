#include <bits/stdc++.h>
using namespace std;

int r, c, visited[20][20], ret;
char a[20][20];
string s;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void go(int y, int x, int num, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        int _next = (1 << (int)(a[ny][nx] - 'A'));
        if ((num & _next) == 0)
            go(ny, nx, num | _next, cnt + 1);
    }
    return;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            a[i][j] = s[j];
        }
    }
    
    go(0, 0, 1 << (int)(a[0][0] - 'A'), 1);
    cout << ret << '\n';
    return 0;
}