/**
 * 무게를 적게 담을 수 있는 가방부터 보석 넣기
 * 보석 중 가치가 최대인 보석만 하나만 넣는 것.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, ret, temp1, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    vector<ll> vv(k);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < k; i++) {
        cin >> vv[i];
    }

    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    priority_queue<ll> pq;

    int j = 0;
    for (int i = 0; i < k; i++) {
        cout << vv[i] << '\n';
        while (j < n && v[j].first <= vv[i]) pq.push(v[j++].second);
        if (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << '\n';
}