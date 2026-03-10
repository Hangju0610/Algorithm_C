#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[15004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 고유한 번호는 100,000보다 작거나 같은 수이다.
    // 즉, 시간초과를 줄일 수 있다.
    if (m > 200000)
        cout << 0 << '\n';
    else {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = a[i] + a[j];
                if (sum == m)
                    ret++;
            }
        }

        cout << ret << '\n';
    }
    
    return 0;
}