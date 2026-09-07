#include <bits/stdc++.h>
using namespace std;

int n, l, r, temp, x, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    cin >> x;
    sort(v.begin(), v.end());

    // 투포인터 시작지점 설정
    l = 0;
    r = n - 1;
    while (l < r) {
        if (v[l] + v[r] == x) {
            cout << v[l] << " : " << v[r] << "\n";
            ret++;
            r--;
        } else if (v[l] + v[r] > x) {
            r--;
        } else {
            l++;
        }
    }
    cout << ret << "\n";
}