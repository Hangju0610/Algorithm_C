#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[26];
int n;

int main() {
    // 1. 단어 s를 받는다.
    cin >> s;

    // for (int i = 0; i < s.size(); i++) {
    //     cnt[(int)s[i] - 97]++;
    // }

    for (char a : s) {
        cnt[a - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";
    return 0;
}

/*
Map을 사용할 경우 : string 기반인 경우
Array : int로 사용. but 1000만, 100만 정도로 넘어가는 경우는 map 기반
*/