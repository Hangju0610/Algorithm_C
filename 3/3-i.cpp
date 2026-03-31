#include <bits/stdc++.h>
using namespace std;

const int max_n = 500000;
int visited[2][max_n + 4], a, b, ok, turn = 1;
// 홀짝을 이용하기 위해, visited[2]를 설정
int main() {
    cin >> a >> b;

    // 반례 설정
    if (a == b) {
        cout << 0 << '\n';
        return 0;
    }

    queue<int> q;
    visited[0][a] = 1;
    q.push(a);
    while(q.size()) {
        b += turn;
        if (b > max_n)
            break;
        if (visited[turn % 2][b]) {
            ok = true;
            break;
        }

        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int x = q.front();
            q.pop();
            for (int nx : { x + 1, x - 1, x * 2}) {
                if (nx < 0 || nx > max_n || visited[turn % 2][nx])
                    continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
                if (nx == b) {
                    ok = 1;
                    break;
                }
                q.push(nx);
            }
            if (ok)
                break;
        }
        if (ok)
            break;
        turn++;
    }

    if (ok)
        cout << turn << '\n';
    else
        cout << -1 << '\n';
    return 0;
}

/*
홀짝을 적용할 줄 알아야 한다.
밑에는 메모리 초과 난 방식.
*/


// #include <bits/stdc++.h>
// using namespace std;
// const int max_n = 1000000;
// const int max_k = 500000;
// int n, k, now_n, now_k, cnt = 0;
// struct A {
//     int a, b, c;
// };

// queue<A> q;

// int main() {
//     cin >> n >> k;
//     q.push({n, k, 1});

//     while(!q.empty()) {
//         now_n = q.front().a;
//         now_k = q.front().b;
//         cnt = q.front().c;
//         q.pop();
//         if (now_n == now_k) {
//             break;
//         } else if (now_k > max_k) {
//             cout << "-1" << '\n';
//             return 0;
//         }

//         int next_k = now_k + cnt;

//         for (int next_n : {now_n + 1, now_n - 1, now_n * 2}) {
//             if (next_n >= max_n || next_n < 0)
//                 continue;
//             q.push({next_n, next_k, cnt + 1});
//         }
//     }

//     cout << cnt - 1 << '\n';
//     return 0;
// }