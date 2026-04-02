#include <bits/stdc++.h>
using namespace std;
int k, check[10];
char op[10];
vector<string> ret;

bool good(char x, char y, char op) {
    if (x > y && op == '>')
        return true;
    if (x < y && op == '<')
        return true;
    return false;
}

void go(int idx, string num) {
    if (idx == k + 1) {
        ret.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (check[i])
            continue;
        if (idx == 0 || good(num[idx - 1], i + '0', op[idx - 1])) {
            check[i] = 1;
            go(idx + 1, num + to_string(i));
            check[i] = 0;
        }
    }
    return;
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> op[i];
    }
    go(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << '\n'
         << ret[0] << '\n';
    return 0;
}

/*
1. 부등호가 주어진다.
2. 부등호에 만족하는 값은 여러개 존재한다. 이때, 부등호에 만족하는 값 중, 최댓값과 최솟값을 작성해라.

-> 순열. 0~9중 몇개만 순서대로 배치해서 완전탐색이 필요하다.
-> 최대값을 기반으로, 시간복잡도는?? -> 10! -> 3650000 정도
-> 완탐으로 가능하다.


k의 범위 1 < k <10
*/