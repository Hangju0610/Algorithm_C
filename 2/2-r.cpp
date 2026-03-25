/*
1. 특정 노드를 삭제한다.
2. 특정 노드를 삭제할 때, 하위 노드들을 모두 삭제하는 로직을 만든다.
3. 리프 노드들을 측정한다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, r, temp, root;
vector<int> adj[54];

int dfs(int here) {
    int ret = 0;
    int child = 0;
    for (int there : adj[here]) {
        if (there == r)
            continue;
        ret += dfs(there);
        child++;
    }
    if (child == 0)
        return 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == -1) {
            root = i;
        } else {
            adj[temp].push_back(i);
        }
            
    }

    cin >> r;
    if (r == root) { // 반례상황
        cout << 0 << '\n';
        return 0;
    }
    cout << dfs(root) << '\n';
    return 0;
}

/*
내가 작성한 틀린 코드
-> 1. 지우거나
2. 그 부분을 탐색하지 않거나.

int n, m, cnt, rt;
map<int, vector<int>> mp;

void check(int i) {
    if (mp.find(i) == mp.end()) { // mp[i].size() -> 이렇게 넣으면, mp가 없을 때, 바로 살아난다.
        cnt++;
        return;
    }

    bool hasChild = false;
    for (auto j : mp[i])
    {
        if (j == m)
            continue;
        hasChild = true;
        check(j);
    }

    if (!hasChild) {
        cnt++;
    }
}

void go(int k) {
    for (auto s : mp[k]) {
        go(s);
    }
    mp.erase(k);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        mp[i] = {};
        if (temp == -1) {
            rt = i;
        }
        if (temp != -1) {
            mp[temp].push_back(i);
        }
    }
    cin >> m;

    go(m);
    if (mp.size() != 0) {
        check(rt);
    }

    

    // for (auto c : mp) {
    //     cout << "노드 " << c.first << "의 자식 : ";
    //     for (auto d : c.second)
    //     {
    //         cout << d << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << mp.size() << '\n';
    cout << cnt;

    return 0;
}
*/