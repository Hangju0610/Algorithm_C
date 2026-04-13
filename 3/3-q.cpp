#include <bits/stdc++.h>
using namespace std;

int r, c, k, ret;
char a[6][6];
int v[6][6];
string str;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go(int y, int x, int s) {
    if (s > k)
        return;
    if (y == 0 && x == c - 1) {
        if (s == k) {
            ret++;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || v[ny][nx] || a[ny][nx] == 'T')
            continue;
        // 원복
        v[ny][nx] = 1;
        go(ny, nx, s + 1);
        v[ny][nx] = 0;
    }
}

int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            a[i][j] = str[j];
        }
    }
    if (k == 1) {
        cout << 0;
        return 0;
    }

    v[r-1][0] = 1;
    go(r-1, 0, 1);
    cout << ret;
}

/*
완탐 + dfs 문제

왼쪽 아래에서 시작해서, 오른쪽 상단 끝
시작점과 끝점 설정이 중요

visited에 해당 값을 할당하는 방법도 있다.
#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, visited[10][10]; 
char a[10][10];
string s; 
int go(int y, int x){
	if(y == 0 && x == m - 1){
		if(k == visited[y][x]) return 1;
		return 0; 
	}
	int ret = 0; 
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 'T')continue;
		visited[ny][nx] = visited[y][x] + 1; 
		ret += go(ny, nx);
		visited[ny][nx] = 0;
	}
	return ret; 
}
int main(){
	cin >> n >> m >> k; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		for(int j = 0; j < m; j++){
			a[i][j] = s[j];
		}
	} 
	visited[n - 1][0] = 1; 
	cout << go(n - 1, 0) << "\n";
}
*/