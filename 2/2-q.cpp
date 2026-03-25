#include <bits/stdc++.h>
using namespace std;

int a[101][101], n, m, t, cnt;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    if (a[y][x] == 1) {
        a[y][x] = 2;
        return;
    }

    a[y][x] = 2; // 공기 칸도 방문 처리

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 2)
            continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                cnt++;
            }
        }
    }

    while(cnt > 0) {
        dfs(0, 0);
        t++;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 2) {
                    a[i][j] = 0;
                }
                if (a[i][j] == 1) {
                    temp++;
                }
            }
        }
        if (temp == 0) {
            break;
        } else {
            cnt = temp;
        }
    }
    cout << t << '\n';
    cout << cnt;
    return 0;
}

/*
1. 치즈를 녹여. 이번턴에 녹는 치즈는 2로 표기한다.
1-1. 0,0부터 dfs를 시작한다. 가장자리는 무조건 0이다. 
2. 2로 표기된 부분을 0으로 치환
3. 남는 치즈의 개수 확인
4. 1 ~ 3을 다시 또 반복 진행


해설 답안

나는 방문을 2로 처리하고 기존거를 계속 반복했다.
visited해도 상관없을듯?

#include <bits/stdc++.h>
using namespace std; 
int a[104][104], visited[104][104];
int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};   
int n, m, cnt, cnt2;
vector <pair<int,int>>v;
void go(int y,int x){
    visited[y][x] = 1;
    if(a[y][x] == 1){
        v.push_back({y,x});
        return;
    }
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue; 
        go(ny,nx);
    }
    return;
}


int main(){ 
    cin >> n >> m; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    while(true){ 
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        v.clear(); 
        go(0,0); 
        cnt2 = v.size();
        for(pair<int, int> b : v){ 
            a[b.first][b.second] = 0;
        }   
        bool flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != 0) flag = 1;
            }
        }
        cnt++;
        if(!flag) break;
    }
    cout << cnt << '\n' << cnt2 << '\n'; 
}


*/