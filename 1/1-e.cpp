#include <bits/stdc++.h>
using namespace std;

int a[26], n;
string s = "";

int main() {
    // 1. 선수 몇명인지 받는다.
    cin >> n;

    // 2. 선수마다 앞글자를 받아서, 알파벳마다 추가한다.
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        a[name[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (a[i] >= 5) {
            char c = i + 97;
            s += c;
            // ret+=  i + 'a'; 이것도 된다.
        }
    }

    if (s == "")
        cout << "PREDAJA" << '\n';
    else
        cout << s << '\n';

    return 0;
}