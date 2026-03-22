#include <bits/stdc++.h>
using namespace std;
string s;
bool b1 = true, b2 = true, ret = true;         // 이번턴 모음일 경우 true, 자음일 경우 false
int c1, c2; // c1 : 모음 개수 체크, c2 : 자음 혹은 모음이 3개 연속으로 오는 경우 c3: 연속된 것 2개 이상.
vector<char> p = {'a', 'e', 'i', 'o', 'u'};

int main() {
    while(true) {
        cin >> s;
        // 기저 사례
        if (s == "end") {
            break;
        }

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            auto l = find(p.begin(), p.end(), c);
            bool innerBool = true;
            // 모음인지 체크
            if (l != p.end()) {
                c1++;
                innerBool = true;
            } else {
                innerBool = false;
            }

            // 조건 추가
            if (innerBool != b2) {
                b2 = innerBool;
                c2 = 1;
            } else {
                c2++;
            }

            if (c2 >= 3) {
                ret = false;
            }

            // 전 문자랑 같은지 비교
            if (i > 0) {
                if (s[i] == s[i - 1]) {
                    string t1 = string(1, s[i - 1]) + string(1, s[i]);
                    if (t1 != "ee" && t1 != "oo")
                    {
                        ret = false;
                        // cout << "c3 false : " << t1 << '\n';
                    }
                }
            }
        }
        if (c1 == 0) {
            ret = false;
        }

        if (ret == false) {
            cout << "<" << s << "> is not acceptable." << '\n';
        } else {
            cout << "<" << s << "> is acceptable." << '\n';
        }

        ret = true;
        c1 = 0;
        c2 = 0;
        b1 = true;
        b2 = true;
    }
}

/*
모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다. -> flag
모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다. -> flag
같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.

패스워드는 한글자 이상 20글자 이하의 문자열
flag 처리로 할 수 있을 것 같은데??

// 깔끔한 버전
#include <bits/stdc++.h>
using namespace std;  
string s; 
int lcnt, vcnt; 
bool isVowel(int idx){
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}
int main () { 
	while(true){
		cin >> s; 
		if(s == "end")break; 
		lcnt = vcnt = 0;
		bool flag = 0;
		bool is_include_v = 0;
		int prev = -1;
		for(int i = 0; i < s.size(); i++){
			int idx = s[i]; 
			if(isVowel(idx))lcnt++, vcnt = 0, is_include_v = 1;
			else vcnt++, lcnt = 0;
			if(vcnt == 3 || lcnt == 3) flag = 1; 
			if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){
				flag  = 1;
			} 
			prev = idx;
		}  
		if(is_include_v == 0) flag = 1;
		if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	} 
	return 0;
}
*/

