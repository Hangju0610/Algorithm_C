#include <bits/stdc++.h>
using namespace std;

string s, ret;
int cnt[200], flag;
char mid;

// 1. 글자를 받는다.
/*
1 - 2 글자 개수를 다 받고, 그 다음에 cnt 함수로 만들어서 풀기
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (char a : s)
        cnt[a]++;
    

    // 오름차순 정렬을 해야 하기 때문에 반복문은 반대로
    for (int i = 'Z'; i >= 'A'; i--) {
        if (cnt[i]) {
            if (cnt[i] % 2 == 1) {
                mid = char(i);
                flag++;
                cnt[i]--;
            }
            if(flag == 2) {
                break;
            }
            for (int j = 0; j < cnt[i]; j += 2) {
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }

    if (mid)
        ret.insert(ret.begin() + ret.size() / 2, mid);
    if (flag == 2) cout << "I'm Sorry Hansoo\n";
	else cout << ret << "\n"; 
}

/*
팰린드롬 시, 홀수가 2개 이상이면 불가능.
1개는 s의 길이가 홀수일 때만 가능하다.
*/