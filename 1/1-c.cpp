#include <bits/stdc++.h>
using namespace std;
int a, b, c, use_time[104];
int sum;

void add_time() {
    int s, e;
    cin >> s >> e;
    for (int i = s + 1; i <= e; i++) {
        use_time[i]++;
    }

    return;
}

int main() {
    // 1. a, b, c 시간을 입력받는다.
    cin >> a >> b >> c;

    // 2. 시간 별 주차장에 보낸 시간 별로 배열에 넣는다. 차는 최대 3대까지만 주차할 수 있다.
    for (int i = 0; i < 3; i++) {
        add_time();
    }

    for (int i : use_time) {
        if (i == 1)
        {
            sum += a * i;
        }
        else if (i == 2)
        {
            sum += b * i;
        }
        else if (i == 3)
        {
            sum += c * i;
        }
    }
    cout << sum << "\n";
    return 0;
}