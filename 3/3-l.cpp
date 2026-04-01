#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[21][21];
map<char, int> mp;
string s;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int go(int y, int x, int cnt) {
    cnt++;
    int result = cnt; // 현재 경로 길이를 result로 분리
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= r || nx < 0 || nx >= c || mp[a[ny][nx]] == 1)
            continue;
        mp[a[ny][nx]] = 1;
        result = max(result, go(ny, nx, cnt)); //cnt는 변경하지 않는다.
        mp[a[ny][nx]] = 0;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            a[i][j] = s[j];
        }
    }

    mp[a[0][0]] = 1;
    
    int cnt = go(0, 0, 0);
    cout << cnt;
}

/*
최대 반복 = 20 * 20 = 400

1. 최대로 갈 수 있는 수 -> dfs
2. 재귀 함수로 진행 -> 재귀 후 원복 과정 추가.
3. 기억은 map으로 진행하기.

0,0 부터 시작. map에 추가하기.
재귀로 cnt를 받자.

전형적인 완전탐색 문제이다.
상당히 쉬운 문제이지만, 시간 복잡도가 큰 문제이다.

3^26, 최소로 해도 2^26이기 때문에, 굉장히 크다.
완전탐색으로 할 수 있는가?? 긴가민가 하면서 풀어봐야 한다.

// 다른 방식
#include <bits/stdc++.h>
using namespace std;
int R, C, ret, ny, nx, visited[30];
char a[21][21];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = { 0, 1, 0, -1}; 
void go(int y, int x, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int next = (int)(a[ny][nx] - 'A');
        
        if(visited[next] == 0){
            visited[next] = 1; 
            go(ny, nx, cnt + 1);
            visited[next] = 0;  
        } 
    }
    return;
}
int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }
    visited[(int)a[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << ret << '\n';
    return 0;
}



*/