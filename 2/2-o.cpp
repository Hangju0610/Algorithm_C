#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string str) {
    stack<char> st;
    for (char c : str) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == ']'){
            if (st.size() == 0)
                return false;
            if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '['))
            {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    while(true) {
        getline(cin, s); // 문장 하나 받을 때는 getline으로
        
        if (s == ".")
            break;
        
        if (check(s))
            cout << "yes\n";
        else cout << "no\n";
    }
}

/*
스택이 비어있는지 확인하고 return 할 것.
*/