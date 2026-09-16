#include <bits/stdc++.h>
using namespace std;

int n, a[100004], cnt[100004], s, e;
long long ret;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    s = 0;
    e = 0;

    while (e < n) {
        if (!cnt[a[e]]) {
            cnt[a[e]] = 1;
            e++;
            continue;
        } else {
            ret += e - s;
            cnt[a[s]]--;
            s++;
        }
    }
    ret += (long long)(e - s) * (e - s + 1) / 2;
    cout << ret << '\n';
}