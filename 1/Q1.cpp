#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100000];
int b, c;

void psum(int b, int c) {
    int psum = 0;
    for (int i = b; i <= c; i++) {
        psum += a[i];
    }
    cout << psum << "\n";
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b >> c;
        psum(b, c);
    }
    return 0;
}
/*
단순 생각했을 경우, n과 m이 10만번이면
O(n^2)이다.

즉, 단순하게 접근하면 시간초과이다.
*/