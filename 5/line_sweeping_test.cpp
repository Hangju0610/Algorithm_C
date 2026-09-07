/**
 * 라인스위핑 테스트
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll st, ed, ret, from, to;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<pair<ll, ll>> v;

    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end());
    st = v[0].first;
    ed = v[0].second;

    // 이어져 있는 경우
    for (int i = 1; i < n; i++) {
        if (ed < v[i].first) {
            ret += ed - st;
            st = v[i].first;
            ed = v[i].second;
        } else {
            ed = v[i].second;
        }

        cout << st << " : " << ed << "\n";
    }
    ret += ed - st;
    cout << ret << '\n';
}