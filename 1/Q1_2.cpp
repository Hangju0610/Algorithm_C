#include <bits/stdc++.h>
using namespace std;
int a[100004], b, c, psum[100004], n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b >> c;
        cout << psum[c] - psum[b - 1] << "\n";
    }
    return 0;
}

/*
이렇게 미리 계산해놓는 누적합이 있는 경우
O(N)으로 변경할 수 있다.
*/