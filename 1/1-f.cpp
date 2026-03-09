#include <bits/stdc++.h>
using namespace std;

vector<char> a, b;
string s, ret;

int main() {
    // 1. 13개 이동한 소문자 배열과 13개 이동한 대문자 배열을 만든다.
    for (int i = 0; i < 26; i++) {
        a.push_back(i + 'a');
        b.push_back(i + 'A');
    }

    rotate(a.rbegin(), a.rbegin() + 13, a.rend());
    rotate(b.rbegin(), b.rbegin() + 13, b.rend());

    getline(cin, s);

    // 2. 대소문자 배열에 맞게 언어를 넣어준다.
    for (auto i : s) {
        if (i <= 'Z' && i >= 'A')
        {
            ret += b[i - 'A'];
        }
        else if (i <= 'z' && i >= 'a') {
            ret += a[i - 'a'];
        } else {
            ret += i;
        }
    }
    cout << ret << '\n';
    return 0;
}

/*
    for(int i = 0; i < s.size(); i++){
        // 대문자인경우
        if(s[i] >= 65 && s[i] < 97){
            if(s[i] + 13 > 90) s[i] = s[i] + 13 - 26; 
            else s[i] = s[i] + 13;  
        }else if(s[i] >= 97 && s[i] <= 122){
            if(s[i] + 13 > 122)s[i] = s[i] + 13 - 26; 
            else s[i] = s[i] + 13;  
        }
        cout << s[i];  
    } 

    이 방법도 있다.
    외우자 A = 65, a = 97
    알파벳은 26개
*/