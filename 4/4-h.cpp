#include <bits/stdc++.h>
using namespace std;

int a[51][51], visited[51][51], n, m, room_num = 1, max_room_size, max_d_room_size;
vector<int> room_size;
int dy[4] = {0, -1, 0, 1}; // 서 = 1, 북 = 2, 동 = 4, 남 = 8
int dx[4] = {-1,0, 1, 0};
vector<set<int>> connected_room_set(2500);

int check_room(int y, int x, int cnt) {
    visited[y][x] = room_num;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;  // 범위 밖이면 스킵
        if (!(a[y][x] & (1 << i)) && visited[ny][nx] == 0) {
            // cout << x << "," << y << " 방 " << nx << "," << ny << " 방향 이동 : " << room_num << "\n";
            cnt = check_room(ny, nx, cnt);
        } else if (visited[ny][nx] != room_num && visited[ny][nx] != 0) {
            connected_room_set[visited[ny][nx]].insert(room_num);
            connected_room_set[room_num].insert(visited[ny][nx]);
        }
    }
    return cnt;
}

int main() {
    cin >> m >> n;
    connected_room_set.resize(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int room_count = 0;
            if (visited[i][j] == 0) {
                room_count = check_room(i, j, 0);
            }
            if (room_count != 0) {
                room_num++;
                room_size.push_back(room_count);
            }
            max_room_size = max(max_room_size, room_count);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << "\n";
    // }

    // for (int v: room_size) {
    //     cout << v << " ";
    // }

    // for (set<int> v: connected_room_set) {
    //     for (int z: v) {
    //         cout << z << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < room_size.size(); i++) {
        for (int j:connected_room_set[i + 1]) {
            // cout << i + 1 << "+" << j << " 덧셈 결과 : " << room_size[i] + room_size[j - 1] << "\n";
            max_d_room_size = max(max_d_room_size, room_size[i] + room_size[j - 1]);
        }
    }
    cout << room_size.size() << "\n"
         << max_room_size << "\n"
         << max_d_room_size << "\n";
}

// dfs + 벽 부수는 방법

// #include <bits/stdc++.h>
// using namespace std;   
// const int dy[] = {0, -1, 0, 1}; 
// const int dx[] = {-1, 0, 1, 0}; 
// int visited[51][51], a[51][51], cnt, compSize[2504], n, m, mx, big; 
// int dfs(int y, int x, int cnt){
//     if(visited[y][x]) return 0; 
//     visited[y][x] = cnt; 
//     int ret = 1; 
//     for(int i = 0; i < 4; i++){
//         if(!(a[y][x] & (1 << i))){
//             int ny = y + dy[i]; 
//             int nx = x + dx[i]; 
//             ret += dfs(ny, nx, cnt); 
//         } 
//     } 
//     return ret; 
// }
// int main(){
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             cin >> a[i][j]; 
//         }
//     }
//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             if(!visited[i][j]){
//                 cnt++; 
//                 compSize[cnt] = dfs(i, j, cnt);  
//                 mx = max(mx, compSize[cnt]);
//             } 
//         }
//     }
//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             if(i + 1 < m){
//                 int a = visited[i + 1][j]; 
//                 int b = visited[i][j]; 
//                 if(a != b){ 
//                     big = max(big, compSize[a] + compSize[b]); 
//                 }
//             }
//             if(j + 1 < n){
//                 int a = visited[i][j + 1]; 
//                 int b = visited[i][j]; 
//                 if(a != b){ 
//                     big = max(big, compSize[a] + compSize[b]); 
//                 }
//             } 
//         } 
//     } 
//     cout << cnt << "\n" << mx << "\n" << big <<'\n'; 
//     return 0;
// }

