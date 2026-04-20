#include <bits/stdc++.h>
using namespace std;

int main() {
    // cout << (9 & 8) << '\n';
    // cout << (9 | 5) << '\n';
    // cout << (9 | 6) << '\n';
    // cout << (~8) << '\n';
    int S = 18;
    int index = 1;
    S &= ~(1 << index); // 16
    cout << S << '\n';
}