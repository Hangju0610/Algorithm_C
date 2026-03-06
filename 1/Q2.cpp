#include <bits/stdc++.h>
using namespace std;

int a[104], n, sum;
double ret;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ret = double(sum) / n;

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << "\n";

    cout << fixed << setprecision(2) << ret << "\n";
    return 0;
}
