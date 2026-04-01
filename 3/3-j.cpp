#include <bits/stdc++.h>
using namespace std;

int n, m, yy1, xx1, yy2, xx2, visited[304][304], ret, y, x;
string s;
char a[304][304];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    cin >> yy1 >> xx1 >> yy2 >> xx2;
    xx1--; yy1--; xx2--; yy2--;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    queue<pair<int, int>> q;
    q.push({yy1, xx1});
    visited[yy1][xx1] = 1;
    int cnt = 0;
    while (a[yy2][xx2] != '0') {
        cnt++;
        queue<pair<int, int>> temp;
        while(q.size()) {
            tie(y, x) = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
                    continue;
                visited[ny][nx] = cnt;
                if (a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push({ny, nx});
                } else{
                    q.push({ny, nx});
                }
            }
        }
        q = temp;
    }
    cout << visited[yy2][xx2];
    return 0;
}

/*
queue를 두개 쓰는 방식
해당 방식을 잘 생각해보자.

1차원으로 생각하면 편하다.
*/