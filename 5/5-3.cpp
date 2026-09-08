#include <bits/stdc++.h>
using namespace std;

int n, ret;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp, temp2;
        cin >> temp >> temp2;
        v.push_back({temp, temp2});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            // 최소를 제거
            pq.pop();
        }
    }
    while (pq.size()) {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << "\n";
}