#include <bits/stdc++.h>
using namespace std;
int n, a[1004], cnt;
int go(int l, int r) {
    cnt++;
    if (l == r)
        return a[l];
    int mid = (l + r) / 2;
    int sum = go(l, mid) + go(mid + 1, r);
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i - 1] = i;
    }
    int sum = go(0, n - 1);
    cout << sum << '\n';
    cout << "cnt : " << cnt << '\n';
}

/*
테스트 시
10
55
cnt : 19

5
15
cnt : 9

30
465
cnt : 59

즉, (2n - 1)의 횟수이므로, 빅오표기법으로 O(n)이 성립

점화식을 한번 그려보면서 해보자.
*/