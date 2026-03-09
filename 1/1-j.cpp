#include <bits/stdc++.h>
using namespace std;
map<string, int> p;
string s1, s2;
int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> s1 >> s2;
            p[s2]++;
        }
        int sum = 1;
        for (auto k : p){
            sum *= k.second + 1; // 어떤 의상 종류에서, 입지 않은 케이스를 1개 추가한다.
        }
        cout << sum - 1 << '\n'; // 마지막에 아무것도 입지 않은 케이스만 뺀다.
        p.clear();
    }
}

/*

*/
