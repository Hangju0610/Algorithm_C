#include <bits/stdc++.h>
using namespace std;

// int a[7] = {64, 32, 16, 8, 4, 2, 1}; // 비트마스킹 수

int x, cnt;

int main() {
    cin >> x;
    // 1. 반복 진행
    for (int i = 0; i < 8; i++) {
        if (x & (1 << i)) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}


// 간단하게 2진법으로 풀어버리는 교안도 존재.
// #include <bits/stdc++.h>
// using namespace std;
// int n, ret = 1;
// int main(){ 
//     cin >> n; 
//     while(n != 1){
//         if(n & 1) ret++; 
//         n /= 2;
//     }
//     cout << ret << '\n';
//     return 0;
// }