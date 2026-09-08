#include <bits/stdc++.h>
using namespace std;

string s, keyword, stk;
/**
 * 1. 언어 조회 방식
 * while로 동작 진행
 *
 * 2. 1,000,000의 길이
 * 12ab112ab2ab
 * 1 12ab 2abb
 * 0 1
 *
 * 이거 어떻게 찾을 건데? pass
 * stack이 필요함.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> keyword;

    for (char c : s) {
        stk.push_back(c);
        if (stk.size() >= keyword.size() &&
            stk.compare(stk.size() - keyword.size(), keyword.size(), keyword) ==
                0) {
            stk.erase(stk.size() - keyword.size());
        }
    }

    if (stk.empty()) {
        cout << "FRULA" << '\n';
    } else {
        cout << stk << '\n';
    }
}