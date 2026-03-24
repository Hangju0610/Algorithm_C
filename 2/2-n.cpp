#include <bits/stdc++.h>
using namespace std;

string s;
int t;


int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        stack<char> st;
        bool flag = 1;
        for (char c : s) {
            if (c == '(')
                st.push(c);
            else {
                if (st.size() == 0) {
                    flag = 0;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if (st.size() != 0) {
            flag = 0;
        }
        if (flag == 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}