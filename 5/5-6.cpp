#include <bits/stdc++.h>
using namespace std;

/**
 * 가방에는 최대 한 개의 보석만 넣을 수 있다.
 * 1. 값어치가 가장 많이 나가는 것, 그 중에서 무거운 것부터.
 * 2. 가벼운 가방부터 비교해서 넣을 수 있으면 넣기.
 */

typedef long long ll;
int n, k;
ll m, v, c, ret;
vector<pair<ll, ll>> v1;
vector<ll> v2;
priority_queue<ll> pq;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        v1.push_back({m, v});
    }
    for (int i = 0; i < k; i++) {
        cin >> c;
        v2.push_back(c);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && v1[j].first <= v2[i]) {
            pq.push(v1[j].second);
            j++;
        }
        if (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << "\n";
}