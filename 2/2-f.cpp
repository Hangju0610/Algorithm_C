#include <bits/stdc++.h>
using namespace std;

int n, m, j, l, r, temp, ret;
int main() {
    cin >> n >> m >> j;
    l = 1; // l은 바구니의 시작 point, r은 바구니의 끝 point;
    for (int i = 0; i < j; i++) {
        r = l + m - 1; // r의 경우, l과 m을 더한 값의 -1을 한다. m이 1일때와 2일때를 생각해보자.
        cin >> temp;
        if (temp >= l && temp <= r)
            continue;
        else {
            if (temp < l) {
                ret += (l - temp);
                l = temp;
            } else {
                l += (temp - r);
                ret += (temp - r);
            }
        }
    }

    cout << ret << '\n';
    return 0;
}

/*
이거 시작 지점 같은거 안잡아줘도 되나??
가장 처음에 바구니는 왼쪽 M칸을 차지하고 있다. << 이 부분 안읽음
*/