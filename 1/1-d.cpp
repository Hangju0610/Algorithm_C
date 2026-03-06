#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    // 1. 단어 받기
    cin >> s;
    
    // 2. 단어 뒤집기

    string re = s;
    reverse(re.begin(), re.end());

    // 3. 비교
    if (re == s) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}