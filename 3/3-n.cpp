/**
 * k의 범위 = 1 ~ 10
 * 즉, 2^k - 1의 노드 개수 존재
 * 1 초	128 MB
 * 메모리 적으로 stack을 많이 두는 것은 문제가 될 수도.
 * 완탐으로 풀어야 한다라..?
 * 
 * 얘는 중위순회이다.
 * 그렇다면 중위 순회를 level 별로 만드는 연습을 해야 한다.
 * 
 * 어떻게?? 중간에 있는 값 -> 중간과 초기 사이 값과 중간과 마지막 값 사이가 자식이 된다. -> 이것을 반복한다.
 */

#include <bits/stdc++.h>
using namespace std;
int k, n, a[2048];
vector<int> ret[12];

void go(int min, int max, int level) {
    int index = (min + max) / 2;
    ret[level].push_back(index);

    // 기저 사례 추가

    if (index == min || index == max) {
        return;
    }

    level++;

    go(min, index, level);
    go(index, max, level);

    return;
}

int main() {
    cin >> k;
    n = (int) pow(2, (double)k) - 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    go(0, n, 0);
    for (int i = 0; i < k; i++) {
        for (int num : ret[i]) {
            cout << a[num] << ' ';
        }
        cout << '\n';
    }
}