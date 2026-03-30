#include <bits/stdc++.h>
using namespace std;

int n, l, r, a[51][51], visited[51][51], ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool bfs(int y, int x) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    visited[y][x] = 1;
    int c = 1;
    int sum = 0;
    q.push({y, x});
    q2.push({y, x});
    sum += a[y][x];
    while (!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            if (visited[ny][nx] == 1)
                continue;

            int comp = abs(a[y][x] - a[ny][nx]);

            if (comp >= l && comp <= r)
            {
                c++;
                q.push({ny, nx});
                q2.push({ny, nx});
                sum += a[ny][nx];
                visited[ny][nx] = 1;
            }
        }
    }

    int avg = sum / c;

    while(!q2.empty()) {
        tie(y, x) = q2.front();
        q2.pop();
        a[y][x] = avg;
    }

    bool flag = false;

    if (c >= 2) {
        flag = true;
    }

    return flag;
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while(true) {
        int flag = false;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j ++) {
                if (visited[i][j] == 0) {
                    int temp = bfs(i, j);
                    if (flag == false && temp == true) {
                        flag = true;
                    }
                }
            }
        }
        if (flag == false)
            break;
        else
            ret++;
    }
    cout << ret;
}

/*

dfs 방식
#include <bits/stdc++.h>
using namespace std;
int visited[54][54], a[54][54], n, l, r, sum, cnt; 
const int dy[]={-1,0,1,0};
const int dx[] ={0,1,0,-1}; 
vector<pair<int,int>>v;
void dfs(int y,int x){ 
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n || visited[ny][nx])continue;
        if(abs(a[ny][nx]- a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            visited[ny][nx] =1;
            v.push_back({ny,nx});
            sum += a[ny][nx];
            dfs(ny,nx);
        }
    }
}

int main(){ 
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    while(true){
        bool flag =0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i,j});
                    sum = a[i][j];
                    dfs(i,j);
                    if(v.size() == 1) continue;  
                    for(pair<int,int> b : v){ 
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                } 
            }
        }
        if(!flag) break;  
        cnt++;
    } 
    cout<< cnt << "\n";
    return 0;
}
*/
