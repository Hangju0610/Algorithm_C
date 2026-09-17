#include <bits/stdc++.h>
using namespace std;

int k, n, a[104], visited[104], cnt;
const int INF = 987654321;
vector<int> v;

int main() {
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        // 이 원소 안쓰고 있는 경우
        if (!visited[a[i]]) {
            // 콘센드 다 차있는 경우
            if (v.size() == k) {
                int last_idx = 0, pos;

                // 콘센트 꼽혀 있는 걸로 비교
                for (int _a : v) {
                    int here_pick = INF;
                    for (int j = i + 1; j < n; j++) {
                        if (_a == a[j]) {
                            here_pick = j;  // 가장 가까운 미래
                            break;
                        }
                    }

                    // 가장 멀리 있는 걸 파악하고 뽑는다. (미래에 없을 수 있음)
                    if (last_idx < here_pick) {
                        last_idx = here_pick;
                        pos = _a;
                    }
                }
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }

            // 콘센트 꼽고, 방문 처리
            v.push_back(a[i]);
            visited[a[i]] = 1;
        }
    }
    cout << cnt << "\n";
}