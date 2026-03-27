#include <bits/stdc++.h>
using namespace std;

int n, a[1000001], ret[1000001];
stack<int> s;

int main() {
    cin >> n;
    memset(ret, -1, sizeof(ret));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while(s.size() && a[s.top()] < a[i]) {
            ret[s.top()] = a[i];
            s.pop();
        }

        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }
}

// 해당 문제로 풀 경우, O(N^2)이므로, 숫자가 어마어마하게 커진다.
// 1000000 * 1000000 = 1조 
// 따라서 짝짓기 스택으로 적용해서 풀어본다.
// int n, a[1000001], ret[1000001];

// void go(int here) {
//     int temp = -1;
//     for (int i = here + 1; i < n; i++) {
//         if (a[here] < a[i]) {
//             temp = a[i];
//             break;
//         }
//     }
//     ret[here] = temp;
// }

// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     for (int i = 0; i < n; i++) {
//         go(i);
//     }
//     for (int i = 0; i < n; i++) {
//         cout << ret[i] << ' ';
//     }
// }