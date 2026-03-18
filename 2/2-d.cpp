#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt, area, a[101][101], visited[101][101];
vector<int> result;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    cnt++;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (a[ny][nx] || visited[ny][nx])
            continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 1. 배열 칠하기
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                a[y][x]++;
            }
        }
    }
    // 2. dfs 구현
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!a[i][j] && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                result.push_back(cnt);
            }
        }
    }

    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for (int r : result) {
        cout << r << ' ';
    }
}

/*
int 형 dfs 코드
int dfs(int y, int x){
    visited[y][x] = 1; 
    int ret = 1; 
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] == 1) continue; 
		if(a[ny][nx] == 1) continue;
        ret += dfs(ny, nx); // 어차피 재귀함수 dfs내 끝날 시점에서 다 더해서 올 것이다.
    } 
    return ret; 
}


*/