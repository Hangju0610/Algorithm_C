#include <bits/stdc++.h>
using namespace std;
int n, k;
const int maxP = 200000;
int visited[maxP + 4], pre[maxP + 4], ret;
vector<int> v;
queue<int> q;

int main() {
    cin >> n >> k;
    q.push(n);
    visited[n] = 1;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        if (here == k) {
            ret = visited[k];
            break;
        }
        for (int next : {here + 1, here - 1, here * 2}) {
            if (next >= maxP || next < 0 || visited[next]) continue;
            visited[next] = visited[here] + 1;
            pre[next] = here;
            q.push(next);
        }
    }

    for (int i = k; i != n; i = pre[i]) {
        v.push_back(i);
    }

    v.push_back(n);
    cout << ret - 1 << '\n';
    reverse(v.begin(), v.end());
    for(int i : v)
        cout << i << ' ';
    return 0;
}