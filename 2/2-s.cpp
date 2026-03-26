#include <bits/stdc++.h>
using namespace std;

int n, m, maxCnt, visited[10001];
vector<int> a[10004];
map<int, vector<int>> mp;

int dfs(int node) {
    int ret = 1;
    visited[node] = 1;
    for (int i : a[node])
    {
        if (visited[i] == 1)
            continue;
        ret += dfs(i);
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int y = 0;
        int x = 0;
        cin >> y >> x;
        a[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int temp = 0;
        temp = dfs(i);
        if (temp > maxCnt)
            maxCnt = temp;
        mp[temp].push_back(i);
    }

    for (int i : mp[maxCnt]) {
        cout << i << ' ';
    }
    return 0;
}