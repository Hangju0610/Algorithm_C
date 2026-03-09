#include <bits/stdc++.h>
using namespace std;

int n;
string pat, start, pat_end;
vector<bool> ret;

int main() {
    // 1. 앞 뒤 패턴을 받아야 한다.
    cin >> n;
    cin >> pat;

    // 2. *를 기준으로 앞 뒤 패턴을 짤라낸다.

    start = pat.substr(0, pat.find('*'));
    pat_end = pat.substr(pat.find('*') + 1, pat.size());

    int start_size = (int) start.size();
    int end_size = (int) pat_end.size();

    // 3. 받은 문자열이 참 거짓인지 확인한다.
    // 3-1. 앞이 같은지 확인한다.
    for (int i = 0; i < n; i++) {
        string s, s_start, s_end;
        cin >> s;
        if (s.size()< end_size + start_size) {
            ret.push_back(0);
            continue;
        }
        s_start = s.substr(0, start_size);

        
        s_end = s.substr(s.size() - end_size, s.size());

        if (s_start == start && s_end == pat_end) {
            ret.push_back(1);
        } else {
            ret.push_back(0);
        }
    }

    for(bool i : ret) {
        if (i == 0) {
            cout << "NE" << '\n';
        } else {
            cout << "DA" << '\n';
        }
    }
    return 0;
}

/*
#include<bits/stdc++.h> 
using namespace std;   
int n; 
string s, ori_s, pre, suf; 
int main(){
    cin >> n;
    cin >> ori_s;  
    int pos = ori_s.find('*');  
    pre = ori_s.substr(0, pos); 
    suf = ori_s.substr(pos + 1); 
    for(int i = 0; i < n; i++){
        cin >> s; 
        if(pre.size() + suf.size() > s.size()){
            cout << "NE\n";
        }else{
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
            else cout <<"NE\n";  
        } 
    } 
    return 0;
} 
*/