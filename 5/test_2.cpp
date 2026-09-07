/**
 * 그리디 적용 방식
 * 시작하는 시간 적용 시, 그리디에 반례가 존재.
 * 따라서 떠나는 시간으로 정렬 후 계산
 */

#include <bits/stdc++.h>
using namespace std;

int n, idx = 0, ret = 1;
int from, to;
vector<pair<int, int>> students;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int st, end;
        cin >> st >> end;
        students.push_back({end, st});
    }

    sort(students.begin(), students.end());
    from = students[0].second;
    to = students[0].first;

    for (int i = 1; i < n; i++) {
        if (students[i].second < to)
            continue;
        from = students[i].second;
        to = students[i].first;
        ret++;
    }

    cout << ret << '\n';
}