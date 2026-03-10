#include <bits/stdc++.h>
using namespace std;

int n, ret;
string s;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        stack<char> st;

        // 1.무조건 짝수여야 한다.
        if (s.size() % 2 != 0) {
            continue;
        }
        for (char c : s) {
            if (!st.empty() && c == st.top()) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        if (st.empty())
            ret++;
    }
    cout << ret << '\n';
    return 0;
}

/*
stack으로 풀면 된다.
그 게임에 3개 이상 붙으면 터지는 것처럼

문제가 안풀릴때는 회전해가면서 찾는 것도 방법이다.
짝짓기, 폭발 -> stack
*/