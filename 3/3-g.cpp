#include <bits/stdc++.h>
using namespace std;

int n, k, sec = 987654321, visited[200004], cnt[200004];
const int maxP = 200000;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void go(int num) {
    visited[num] = 1;
    cnt[num] = 1;
    queue<int> q;
    q.push(num);
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int next : {now - 1, now + 1, now * 2}) {
            if (0 <= next && next <= maxP) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                } else if (visited[next] == visited[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }
        }
    }
}

int main() {
    fastIO();
    cin >> n >> k;
    if (n == k) {
        cout << "0" << '\n'
             << "1" << '\n';
        return 0;
    }
    go(n);
    cout << visited[k] - 1 << '\n' << cnt[k] << '\n';
    return 0;
}