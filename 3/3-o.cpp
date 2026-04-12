/*
첫째 줄에 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을 수 있는 위치의 개수 H가 주어진다. (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
둘째 줄부터 M개의 줄에는 가로선의 정보가 한 줄에 하나씩 주어진다.
가로선의 정보는 두 정수 a과 b로 나타낸다. (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미이다.
가장 위에 있는 점선의 번호는 1번이고, 아래로 내려갈 때마다 1이 증가한다. 세로선은 가장 왼쪽에 있는 것의 번호가 1번이고, 오른쪽으로 갈 때마다 1이 증가한다.
입력으로 주어지는 가로선이 서로 연속하는 경우는 없다. ->
즉, a번 점선에서 b번 세로선과 b+1번 세로선이 연결되어 있으면, b번 세로선과 b - 1 세로선은 연결되어 있지 않다.
3차원 배열..?

i번 세로선의 결과가 i번이 나오도록 사다리 게임을 조작하려면, 추가해야 하는 가로선 개수의 최솟값을 출력한다.
만약, 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.
-> 최소한의 수 부터 추가해본 다음, 안되면 다음 개수인가?

ok.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, h, ret = 987654321, y, x, a[31][11], maxCount, visited[31][11];
bool flag = false;


bool go() {
    for (int i = 1; i <= n; i++) {
        int now_x = i;
        for (int now_y = 1; now_y <= h; now_y++) {
            if (a[now_y][now_x] == 1) {
                now_x++; // 우측 이동
            } else if (a[now_y][now_x - 1] == 1) {
                now_x--; // 좌측 이동
            }
        }
        // cout << i << "번째 세로줄 결과 : " << now_x << '\n';
        if (now_x != i)
        {
            return false;
        }
    }
    return true;
}

void add(int y, int x, int count) {
    if (flag == true) {
        return;
    }

    if (count == maxCount) {
        flag = go();
        return;
    }

    for (int i = y; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1 || a[i][j-1] == 1)
                continue;
            a[i][j] = 1;
            add(i, j, count + 1);
            a[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> y >> x;
        a[y][x] = 1; // y번 점선에서 x 세로선과 x + 1 세로선이 연결되어있단 의미.
    }

    // 최대 3개 까지만 추가해보고, 안되면 -1이다. 또한 불가능하면 -1이다.
    // 최대 30 * 10
    for (int i = 0; i <= 3; i++) {
        maxCount = i;
        add(0, 0, 0);
        if (flag == true) {
            ret = i;
            break;
        }
    }

    if (ret <= 3) {
        cout << ret << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}