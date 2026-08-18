#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, cnt;
vector<int> adj[1004];
int visited[1004];

void dfs(int here) {
    // cout << here << "\n";
    visited[here] = 1;
    for (int there : adj[here]) {
        if (!visited[there]) dfs(there);
    }
    return;
}

int main() {
    scanf("%1d", &t);
    while(t--) {
        scanf("%d", &n);
        scanf("%d", &m);
        // cout << n << " " << m << "\n";
        cnt = 0;
        // 반복 할 때마다 초기화 진행
        for (int i = 0; i < 1004; i++) adj[i].clear();
        fill(visited, visited + 1004, 0);

        // 간선 지정
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // dfs 진행
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                // cout << "dfs start : " << i << "\n"; 
                dfs(i);
                cnt++;
            }
        }

        // cout << "cnt : " << cnt << "\n";

        // 트리 조건 : A에서 B로 이동 시, 어디로든 1개의 길만 존재 / 간선의 개수 = 노드의 개수 - 1
        if(m == n - 1 && cnt == 1) puts("tree");
        else {
            puts("graph");
        } 
    }
}