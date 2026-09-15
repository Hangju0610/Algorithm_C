#include <bits/stdc++.h>
using namespace std;
int n, st, ed, from, t;
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> from >> t;
        v.push_back({from, t});
    }

    sort(v.begin(), v.end());

    st = v[0].first;
    ed = st + v[0].second;

    for (int i = 1; i < n; i++) {
        if (ed < v[i].first) {
            st = v[i].first;
            ed = st + v[i].second;
        } else {
            ed = ed + v[i].second;
        }
    }

    cout << ed << '\n';
}