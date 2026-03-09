#include <bits/stdc++.h>
using namespace std;

int n, k, t, ret = -10000000;
vector<int> temp;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t;
        temp.push_back(t);
        
        if (i + 1 >= k) {
            int sum = 0;
            for (int j = i; j >= i + 1 - k; j--) {
                sum += temp[j];
            }
            if (sum > ret) {
                ret = sum;
            }
        }
    }
    cout << ret << '\n';
}

/*
최대값을 구하는 것이기 때문에, 최솟값을 먼저 예상하고 구해야 한다.

구간합을 사용하는 방법도 있다.
for(int i = 1; i <= n; i++) {
    cin >> temp;
    psum[i] = psum[i - 1] + temp;
}

for (int i = k; i <= n; i ++) {
    ret = max(ret, psum[i] - psum[i - k]);
}
*/