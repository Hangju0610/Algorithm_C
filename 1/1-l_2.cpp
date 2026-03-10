#include <bits/stdc++.h>
using namespace std;
int n, m, ret;
int a[15004];

void combi(int idx, vector<int> &v) {
    if (v.size() == 2) {
        int b = a[v[0]];
        int c = a[v[1]];
        if (b + c ==m)
            ret++;
        return;
    }

    for (int i = idx + 1; i < n; i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v;
    combi(-1, v);
    cout << ret << '\n';
}