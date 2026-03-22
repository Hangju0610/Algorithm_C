#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> ret;

pair<string, int> go(int i) {
    string temp = "";
    int next_number = s.size();
    for (int j = i; j < s.size(); j++)
    {
        if (s[j] >= '0' && s[j] < '0' + 10) {
            temp += s[j];
        } else {
            next_number = j;
            break;
        }
    }
    // 선행 0 제거
    int start = 0;
    while (start < temp.size() - 1 && temp[start] == '0')
        start++;
    temp = temp.substr(start);
    return {temp, next_number};
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] >= '0' && s[j] < '0' + 10) {
                auto temp = go(j);
                ret.push_back(temp.first);
                j = temp.second;
            }
        }
    }
    sort(ret.begin(), ret.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });
    for (auto i : ret) {
        cout << i << "\n";
    }
    return 0;
}

/*
선생님이 상근이에게 준 종이에는 숫자와 알파벳 소문자로 되어있는 글자가 N줄있다. 상근이는 여기서 숫자를 모두 찾은 뒤, 이 숫자를 비내림차순으로 정리해야한다. 숫자의 앞에 0이 있는 경우에는 정리하면서 생략할 수 있다.
글자를 살펴보다가 숫자가 나오는 경우에는, 가능한 가장 큰 숫자를 찾아야 한다. 즉, 모든 숫자의 앞과 뒤에 문자가 있거나, 줄의 시작 또는 끝이어야 한다.
예를 들어, 01a2b3456cde478에서 숫자를 찾으면 1, 2, 3456, 478이다.
선생님이 준 종이의 내용이 주어졌을 때, 상근이의 숙제를 대신하는 프로그램을 작성하시오.

1. s를 받아
2. 한글자씩 파악한다.
3. 숫자인지 문자인지 파악한다. 숫자인 경우 시작 (함수처리로 만들자)

100자리면 longlong 보다 더 큰 수가 된다.

이럴 때는 string으로 변환해서 문제를 풀어야 한다.

int = 10 ^ 9
longlong = 10 ^ 19

#include <bits/stdc++.h>
using namespace std;   
int n; 
vector<string> v; 
string s, ret;
void go(){   
	while(true){  
		if(ret.size() && ret.front() == '0')ret.erase(ret.begin()); 
		else break;
	}
	if(ret.size() == 0) ret = "0"; 
	v.push_back(ret);
	ret = "";  
}
bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}
int main () {
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
	 	ret = "";
		for(int j = 0; j < s.size(); j++){
			if(s[j] < 65)ret += s[j];
			else if(ret.size()) go(); 
		}
		if(ret.size()) go(); 
	}
	sort(v.begin(), v.end(), cmp);
	for(string i : v)cout << i << "\n"; 
	return 0;
}
*/