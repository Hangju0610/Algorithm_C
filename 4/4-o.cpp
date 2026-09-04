#include <bits/stdc++.h>
using namespace std;

int n, ret;
string s;
stack<int> stk;


// 1. (인 경우 stack에 넣기
// 2. )인 경우 stack에서 빼면서 최대값을 계산하기
// 즉, -1을 처음에 넣고, 시작
int main() {
    cin >> n >> s;
    stk.push(-1);
    for (int i = 0; i < n; i++) 
    {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (!stk.empty()) {
                ret = max(ret, i - stk.top());
            } else {
                stk.push(i);
            }
        }
    }
    cout << ret << '\n';
}