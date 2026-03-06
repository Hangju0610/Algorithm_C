#include <bits/stdc++.h>
using namespace std;
int N, cnt;
void solve(int N) {
    cnt++;
    cout << cnt << '\n';
    if (N == 0)
        return;
    for (int i = 0; i < 3; i++) {
        solve(N - 1);
    }
    return;
}

int main() {
    cin >> N;
    solve(N);
    return 0;
}

/*
재귀함수의 시간 복잡도
메인 로직 * 함수 호출이 몇번 되는가?
O(1) * O(3^n);
*/