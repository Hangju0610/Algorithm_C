#include <bits/stdc++.h>
using namespace std;

int n;
string s;
char a[64][64];

string quard(int size, int y, int x) {
    if (size == 1)
        return string(1, a[y][x]);

    char b = a[y][x];
    string ret = "";
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (b != a[i][j]) {
                // 초기값과 일치하지 않기 때문에 재귀함수 4번 반복 진행
                ret += '(';
                ret += quard(size / 2, y, x);
                ret += quard(size / 2, y, x + (size / 2));
                ret += quard(size / 2, y + (size / 2), x);
                ret += quard(size / 2, y + (size / 2), x + (size / 2));
                ret += ')';
                return ret;
            }
        }
    }
    // 만약 해당 조건에 아무것도 부합하지 않은 경우, 초기값과 모든 값이 동일하기 때문에 초기값을 return
    return string(1, a[y][x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }
    cout << quard(n, 0, 0) << '\n';
    return 0;
}

/*
분할 정복.
다시 풀어보기 진행
*/