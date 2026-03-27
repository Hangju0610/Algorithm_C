#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], minRet;
vector<pair<int, int>> ch, h, r;

int check() {
    vector<int> ret2(h.size(), 0);
    for (auto i : r)
    {
        for (int j = 0; j < h.size(); j++) {
            int d = abs(i.first - h[j].first) + abs(i.second - h[j].second);
            if (ret2[j] == 0 || ret2[j] > d)
                ret2[j] = d;
        }
    }

    int sum = 0;
    for (int i = 0; i < ret2.size(); i++) {
        sum += ret2[i];
    }
    return sum;
}

void add(int here) {
    if (r.size() == m) {
        int sum = check();
        if (minRet == 0 || minRet > sum)
            minRet = sum;
        return;
    }

    for (int there = here + 1; there < ch.size(); there++) {
        r.push_back(ch[there]);
        add(there);
        r.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1)
                h.push_back({i, j});
            else if (a[i][j] == 2)
                ch.push_back({i, j});
        }
    }

    for (int i = 0; i < ch.size(); i++) {
        r.push_back(ch[i]);
        add(i);
        r.pop_back();
    }
    cout << minRet;
}

/*
1. 1 <= N <= 50 ,집의 개수 : 2N, 최대 100개, 집은 1로 표시
2. M(1 ≤ M ≤ 13), 제거해야 될 치킨집. 2로 표시
3. 거리 계산 : |r2 - r1| + |c2 - c1|

1. 완탐 및 제거로 진행
- 치킨집 M개 제거
2. 제거 후 집과 치킨집 거리 최단 계산 진행

*/