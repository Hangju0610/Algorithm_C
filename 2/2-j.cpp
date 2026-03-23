#include <bits/stdc++.h>
using namespace std;
int ret[101][101], h, w;
string s;
void go(int y, int x, int t)
{
    // 기저사례
    if (ret[y][x] == 0 && t != 0)
        return;

    ret[y][x] = t;
    int dx = x + 1;
    int dt = t + 1;
    if (dt > w)
        return;
    return go(y, dx, dt);
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == 'c') {
                ret[i][j] = 0;
            } else {
                ret[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (ret[i][j] == 0) {
                int cnt = 1;
                while(ret[i][j + 1] == -1) {
                    ret[i][j + 1] = cnt++;
                    j++;
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*
1. 처음부터 시작. '.' 인 경우 -1로 ret을 입력
2. 'c'라면 go 함수 시작. 다음 순서까지 'c'가 없다면 끝.
*/