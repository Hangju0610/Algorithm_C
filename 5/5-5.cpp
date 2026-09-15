#include <bits/stdc++.h>
using namespace std;

int n, from, to, st, ed, ret;
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        v.push_back({from, to});
    }

    sort(v.begin(), v.end());

    st = v[0].first;
    ed = v[0].second;
    ret = 1;

    for (int i = 1; i < n; i++) {
        if (ed <= v[i].first) {
            ed = v[i].second;
            ret++;
        } else {
            if (ed > v[i].second) {
                ed = v[i].second;
            }
        }
    }
    cout << ret << '\n';
}

/**
 * end 기반 정렬 방법
 *
 * int from, to, n, idx = 0, ret = 1;
 * int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to, from});
    }
    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;
    for(int i = 1; i < n; i++){
        if(v[i].second < to) continue;
        from = v[i].second; to = v[i].first;ret++;
    }
    cout << ret << '\n';
    return 0;
}
 * }
 */