/**
 * 무식하게 완탐으로 해결하는 방식
 * DFS, BFS 등
 * 시간 복잡도 = 2 ^ N,
 * 
 * 즉 N이 클수록 시간이 오래 걸리므로, 다른 방식으로 해야한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> student;

int dfs(int index, int lastLeave) {
    if (index == n) {
        return 0;
    }
    int result = dfs(index + 1, lastLeave);

    if (student[index].first >= lastLeave) {
        result = max(result, 1 + dfs(index + 1, student[index].second));
    }

    return result;
}

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int st, end;
        cin >> st >> end;
        student.push_back({st, end});
    }

    sort(student.begin(), student.end(), comp);
    cout << dfs(0, -1) << '\n';
}