#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
map<string, int> p;
string p2[100004];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    // 포켓몬을 모두 받는다.
    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        p[a] = i;
        p2[i] = a;
    }

    for (int i = 0; i < m; i++) {
        cin >> s;
        if(atoi(s.c_str()) != 0) {
            cout << p2[atoi(s.c_str())] << '\n';
        } else {
            cout << p[s] << '\n';
        }
    }
    return 0;
}

/*
자료구조의 시간복잡도가 중요한 문제
Array의 탐색 : O(N)
Map의 탐색 : O(logN)
*/